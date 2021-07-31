# JNI_Java
use JNI call C/C++ print hello world

## hello world code
[Java_Source](app/src/main/java/com/ggggght/sayhello/HelloWorld.java)定义native方法
```java
public native void hello();
```

使用`javac`生成`C++`的本地方法实现
```sh
javac -h . HelloWorld.java
```

[C++头文件](app/src/main/java/com/ggggght/sayhello/com_ggggght_HelloWorld.h)生成含有native方法的头文件 <br/>

<br/>
编写C++实现<br/>

[C++实现](app/src/main/java/com/ggggght/sayhello/com_ggggght_HelloWorld.cpp)<br/>

<br/>

编译C++源码
MacOS:
```sh
g++ -c -fPIC -I${JAVA_HOME}/include -I${JAVA_HOME}/include/darwin ${impl_file} -o ${head_file}
```
`${impl_file}` 与 `${head_file}`需替换为需要编译的文件名

[本例中平台编译生成的文件](app/src/main/java/com/ggggght/sayhello/com_ggggght_HelloWorld.o)

```sh
g++ -dynamiclib -o libnative.dylib ${like_file} -lc
```
${like_file}需替换为上述的文件<br/>

使用全路径去运行
```sh
java -cp . -Djava.library.path=/NATIVE_SHARED_LIB_FOLDER com.ggggght.sayhello.HelloWorld
```
1. -Djava.library.path 配置链接库的地址
2. 使用System.load(${fqdn})去加载生成的链接库的地址

## 源码分析 
```java
System.loadLibrary("native");


		#define JNI_LIB_PREFIX "lib"
		#ifdef __APPLE__
		#define JNI_LIB_SUFFIX ".dylib"
		#else
		#define JNI_LIB_SUFFIX ".so"
		#endif
        
		JNIEXPORT jstring JNICALL
		Java_java_lang_System_mapLibraryName(JNIEnv *env, jclass ign, jstring libname)
		{
		int len;
		int prefix_len = (int) strlen(JNI_LIB_PREFIX);
		int suffix_len = (int) strlen(JNI_LIB_SUFFIX);

		jchar chars[256];
		if (libname == NULL) {
		JNU_ThrowNullPointerException(env, 0);
		return NULL;
		}
		len = (*env)->GetStringLength(env, libname);
		if (len > 240) {
		JNU_ThrowIllegalArgumentException(env, "name too long");
		return NULL;
		}
		cpchars(chars, JNI_LIB_PREFIX, prefix_len);
		(*env)->GetStringRegion(env, libname, 0, len, chars + prefix_len);
		len += prefix_len;
		cpchars(chars + len, JNI_LIB_SUFFIX, suffix_len);
		len += suffix_len;

		return (*env)->NewString(env, chars, len);
		}


```

mapLibraryName() 会在`libname`前拼接`lib` 并会在`libname`之后拼接lib的后缀名 windows中是`dll` macos是`dylib`  linux是`so`

## JNI的缺陷
- 平台的依赖 失去了<b>write once, run anywhere!</b>的特性
- 增加了复杂性 在运行的JVM与native方法中增加了通信的成本

## 结论
- 为特定平台编译代码通常比直接运行字节码更快
- 使用管理设备的库


## JNI接口函数和指针
本机代码通过调用 JNI 函数来访问 Java VM 功能。 JNI 函数可通过接口指针使用。 接口指针是指向指针的指针。
这个指针指向一个指针数组，每个指针指向一个接口函数。 每个接口函数都位于数组内的预定义偏移量处。
![JNI接口指针内存部局](https://docs.oracle.com/javase/8/docs/technotes/guides/jni/spec/images/designa.gif)