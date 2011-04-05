package njsdl.gl;

public class Log
{
    public static boolean DEBUG = true;
    
	public static void println(String tag, String message)
	{
		if(DEBUG)
			System.out.println("[" + tag + "] " + message);
	}
}
