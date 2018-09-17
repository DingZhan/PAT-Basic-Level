import java.util.*;

public class Main
{
	static void PrintResult(int myScore, double otherScore)
	{
		if(myScore<otherScore)
			System.out.print("Cong");
		else if(myScore>otherScore)
			System.out.print("Gai");
		else
			System.out.print("Ping");
	}
	public static void main(String strs[])
	{
		int M, X, Y, A, B, d;
		double C;
		boolean bFind  = false;
		Scanner scanner = new Scanner(System.in);
		M = scanner.nextInt();
		X = scanner.nextInt();
		Y = scanner.nextInt();
		for(A=99; A>=10; --A)
		{
			B = A/10 + A%10*10;
			d = Math.abs(A-B);
			C = d/(X+0.0);
			if(Math.abs(B-C*Y)<1.0e-5)
			{
				System.out.printf("%d ", A);
				PrintResult(M, A);
				System.out.print(" ");
				PrintResult(M, B);
				System.out.print(" ");
				PrintResult(M, C);
				System.out.println();
				bFind = true;
				break;
			}
		}
		if(!bFind)
			System.out.println("No Solution");
	}
}