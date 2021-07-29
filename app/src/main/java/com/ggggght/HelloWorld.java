package com.ggggght;

public class HelloWorld {
	static {
		System.load("D:\\source\\JNI_Java\\app\\src\\main\\java\\com\\cpp\\native.dll");
	}
	public native String hello();

	public static void main(String[] args) {
		new HelloWorld().hello();
	}
}
