/*
* Copyright (C) 2011 René Jeschke <rene_jeschke@yahoo.de>
* See LICENSE.txt for licensing information.
*/
package com.github.rjeschke.njsdl.gl;

public class Log
{
    public static boolean DEBUG = true;
    
	public static void println(String tag, String message)
	{
		if(DEBUG)
			System.out.println("[" + tag + "] " + message);
	}
}
