/* DO NOT EDIT THIS FILE - it is machine generated */
#include <jni.h>
#include <iostream>
#include "com_ggggght_object_ExampleObjectsJNI.h"
/* Header for class com_ggggght_object_ExampleObjectsJNI */

/*
 * Class:     com_ggggght_object_ExampleObjectsJNI
 * Method:    createUser
 * Signature: (Ljava/lang/String;D)Lcom/ggggght/object/UserData;
 */
JNIEXPORT jobject JNICALL Java_com_ggggght_object_ExampleObjectsJNI_createUser
(JNIEnv *env, jobject thisObject, jstring name, jdouble balance) {

    // Create the object of the class UserData
    jclass userDataClass = env->FindClass("com/ggggght/object/UserData");
    jobject newUserData = env->AllocObject(userDataClass);

    // Get the UserData fields to be set
    jfieldID nameField = env->GetFieldID(userDataClass , "name", "Ljava/lang/String;");
    jfieldID balanceField = env->GetFieldID(userDataClass , "balance", "D");

    env->SetObjectField(newUserData, nameField, name);
    env->SetDoubleField(newUserData, balanceField, balance);

    return newUserData;
}

/*
 * Class:     com_ggggght_object_ExampleObjectsJNI
 * Method:    printUserData
 * Signature: (Lcom/ggggght/object/UserData;)Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_com_ggggght_object_ExampleObjectsJNI_printUserData
(JNIEnv *env, jobject thisObject, jobject userData) {

    // Find the id of the Java method to be called
    jclass userDataClass=env->GetObjectClass(userData);
    jmethodID methodId=env->GetMethodID(userDataClass, "getUserInfo", "()Ljava/lang/String;");

    jstring result = (jstring)env->CallObjectMethod(userData, methodId);
    return result;
  }
