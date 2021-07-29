package com.ggggght;

public class HelloWorld {
	static {
		System.loadLibrary("native");
	}
	public native String hello();

	public static void main(String[] args) {
		new HelloWorld().hello();
	}
}
