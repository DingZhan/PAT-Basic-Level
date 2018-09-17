import java.util.*;

public class Main {

	static final public int MAX_ID = 100000;
	static final public int MAX_K = 1002;
	public static void main(String strs[])
	{
		int N, M, i, id1, id2, K, j, k, t, G[];
		Scanner scanner = new Scanner(System.in);
//		boolean conflicts[] = new boolean[MAX_ID];
		ArrayList conflicts[] = 
			new ArrayList [MAX_ID];
		for(i=0; i<MAX_ID; ++i)
			conflicts[i] = new ArrayList(15);
		N = scanner.nextInt();
		M = scanner.nextInt();
		for(i=0; i<N; ++i)
		{
			id1 = scanner.nextInt();
			id2 = scanner.nextInt();
			conflicts[id1].add(id2);
			conflicts[id2].add(id1);
		}
		G = new int[MAX_K];
		for(i=0; i<M; ++i)
		{
			K = scanner.nextInt();
			for(j=0; j<K; ++j)
				G[j] = scanner.nextInt();
			//test g1, g2 conflicts?
			int g1, g2;
			boolean bConflict = false;
			for(j=0; j<K; ++j)
			{
				g1 = G[j];
				for(k=j+1; k<K; ++k)
				{
					g2 = G[k];
					if(conflicts[g1].contains(g2))
					{
						bConflict = true;
						break;
					}
					/*
					for(t=0; t<conflicts[g1].size(); ++t)
					{
						if(Integer.parseInt(conflicts[g1].get(t).toString())==g2)
						{
							bConflict = true;
							break;
						}
					}*/
					if(bConflict)
						break;
				}
				if(bConflict)
					break;
			}
			if(bConflict)
				System.out.println("No");
			else
				System.out.println("Yes");
		}
	}
}
