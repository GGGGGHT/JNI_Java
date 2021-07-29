#include <iostream>
#include <jni.h>
#include "com_ggggght_HelloWorld.h"

/*
 * Class:     com_ggggght_HelloWorld
 * Method:    hello
 * Signature: ()Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_com_baeldung_jni_HelloWorldJNI_sayHello (JNIEnv* env, jobject thisObject) {
	std::string hello = "Hello from C++ !!";
    std::cout << hello << std::endl;
    return env->NewStringUTF(hello.c_str());
}

