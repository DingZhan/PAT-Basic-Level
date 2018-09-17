import java.util.*;

public class Main {

	public static void main(String strs[])
	{
		Scanner scanner = new Scanner(System.in);
		int A, B, C;
		boolean bFirstPrint = true;
		A = scanner.nextInt();
		B = scanner.nextInt();
		C = A*B;
		while(C!=0)
		{
			if(!(C%10==0 && bFirstPrint))
			{
				System.out.print(C%10);
				bFirstPrint = false;
			}
			C = C/10;
		}
	}
}