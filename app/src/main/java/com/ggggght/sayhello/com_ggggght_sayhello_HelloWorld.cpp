/* DO NOT EDIT THIS FILE - it is machine generated */
#include <jni.h>
#include "com_ggggght_sayhello_HelloWorld.h"
#include <iostream>

/*
 * Class:     com_ggggght_HelloWorld
 * Method:    hello
 * Signature: ()Ljava/lang/String;
 */
 using namespace std;
JNIEXPORT jstring JNICALL Java_com_ggggght_sayhello_HelloWorld_hello
  (JNIEnv* env, jobject thisObject) {
    string hello = "Hello from C++ !!";
    cout << hello << endl;
      return env->NewStringUTF(hello.c_str());
  }


