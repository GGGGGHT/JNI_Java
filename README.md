# JNI_Java
use JIN call C/C++ print hello world 

## code
[Java_Source](app/src/main/java/com/ggggght/HelloWorld.java)定义native方法
```java
public native void hello();
```

使用`javac`生成`C++`的本地方法实现
```sh
javac -h . HelloWorld.java
```

[C++_Source](app/src/main/java/com/ggggght/com_ggggght_HelloWorld.h)生成含有native方法的头文件
