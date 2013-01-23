/*
* Copyright (C) 2011 René Jeschke <rene_jeschke@yahoo.de>
* See LICENSE.txt for licensing information.
*/
package com.github.rjeschke.njsdl.gl;

import java.util.HashMap;

public class ShaderMan
{
	private final static String TAG = "ShaderMan"; 
	private static HashMap<String, Shader> shaders = new HashMap<String, Shader>();
	
	private ShaderMan() { /* */ }
	
	public static Shader get(String name)
	{
		return shaders.get(name);
	}
	
	public static Shader use(String name)
	{
		final Shader shader = shaders.get(name);
		shader.use();
		return shader;
	}
	
	public static boolean sane()
	{
		for(final Shader shader : shaders.values())
		{
			if(!shader.linkOk())
				return false;
		}
		return true;
	}
	
	public static void dispose()
	{
		for(final Shader shader : shaders.values())
			shader.dispose();
		shaders.clear();
	}
	
	public static Shader create(String name, String vsh, String fsh)
	{
		Log.println(TAG, "Creating '" + name + "' -> " + vsh + ", " + fsh);
		if(shaders.containsKey(name))
			Log.println(TAG, "Duplicate shader '" + name + "'");
		final Shader shader = new Shader(Log.DEBUG)
			.attachVertexShader(vsh)
			.attachFragmentShader(fsh)
			.link();
		shaders.put(name, shader);
		return shader;
	}

    public static Shader create(String name, String vsh, String fsh, String[] vertexAttributes, String[] fragmentAttributes)
    {
        Log.println(TAG, "Creating '" + name + "' -> " + vsh + ", " + fsh);
        if(shaders.containsKey(name))
            Log.println(TAG, "Duplicate shader '" + name + "'");
        final Shader shader = new Shader(Log.DEBUG)
            .attachVertexShader(vsh)
            .attachFragmentShader(fsh);
        
        if(vertexAttributes != null)
            shader.setVertexAttributesList(vertexAttributes);
        if(fragmentAttributes != null)
            shader.setFragmentAttributesList(fragmentAttributes);
        
        shader.link();
        shaders.put(name, shader);
        return shader;
    }

    public static Shader create(String name, String vsh, String gsh, String fsh)
	{
		Log.println(TAG, "Creating '" + name + "' -> " + vsh + ", " + gsh + ", " + fsh);
		if(shaders.containsKey(name))
			Log.println(TAG, "Duplicate shader '" + name + "'");
		final Shader shader = new Shader(Log.DEBUG)
			.attachVertexShader(vsh)
			.attachGeometryShader(gsh)
			.attachFragmentShader(fsh)
			.link();
		shaders.put(name, shader);
		return shader;
	}
}
