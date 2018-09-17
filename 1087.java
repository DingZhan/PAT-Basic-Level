
import java.util.*;

public class Main {

	public static void main(String strs[])
	{
		int n, N, v, count=0, lastV = -1;
		Scanner scanner = new Scanner(System.in);
		N = scanner.nextInt();
		for(n=1; n<=N; ++n)
		{
			v = n/2 + n/3 + n/5;
			if(v!=lastV)
			{
				lastV = v;
				++count;
			}
		}
		System.out.println(count);
	}
}
