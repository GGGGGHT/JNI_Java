package com.ggggght.object;

public class ExampleObjectsJNI {
	static {
		System.load("/Users/admin/github/JNI_Java/app/src/main/java/com/ggggght/object/libnative.dylib");
	}

	public static void main(String[] args) {
		ExampleObjectsJNI instance = new ExampleObjectsJNI();
		UserData newUser = instance.createUser("John Doe", 450.67);
		System.out.println(instance.printUserData(newUser));
	}

	public native UserData createUser(String name, double balance);

	public native String printUserData(UserData user);
}
