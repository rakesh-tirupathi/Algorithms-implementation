//implementation of DFS

//recursive solution
import java.util.*;

public class Graph1
{
   /* ------------------------------------------
      Data structure used to represent a graph
      ------------------------------------------ */
   int[][]  adjMatrix;
   int      rootNode = 0;
   int      NNodes;

   boolean[] visited; 

   /* -------------------------------
      Construct a graph of N nodes
      ------------------------------- */
   Graph1(int N)
   {
      NNodes = N;
      adjMatrix = new int[N][N];
      visited = new boolean[N];
   }

   Graph1(int[][] mat)
   {
      int i, j;

      NNodes = mat.length;

      adjMatrix = new int[NNodes][NNodes];
      visited = new boolean[NNodes];


      for ( i=0; i < NNodes; i++)
         for ( j=0; j < NNodes; j++)
            adjMatrix[i][j] = mat[i][j];
   }

   public void dfs(int i)
   {
      int j;

      visited[i] = true;

      printNode(i);

      for ( j = 0; j < NNodes; j++ )
      {
	 if ( adjMatrix[i][j] > 0 && !visited[j] )
            dfs(j);
      }
   }


   public void clearVisited()
   {
      int i;

      for (i = 0; i < visited.length; i++)
         visited[i] = false;
   }

   public void printNode(int n)
   {
      System.out.println(n);
   }
}

public class TestProg
{

   public static void main(String[] args)
   {
//                        0  1  2  3  4  5  6  7  8
// ===================================================
      int[][] conn = {  { 0, 1, 0, 1, 0, 0, 0, 0, 1 },  // 0
			{ 1, 0, 0, 0, 0, 0, 0, 1, 0 },  // 1
			{ 0, 0, 0, 1, 0, 1, 0, 1, 0 },  // 2
			{ 1, 0, 1, 0, 1, 0, 0, 0, 0 },  // 3
			{ 0, 0, 0, 1, 0, 0, 0, 0, 1 },  // 4
			{ 0, 0, 1, 0, 0, 0, 1, 0, 0 },  // 5
			{ 0, 0, 0, 0, 0, 1, 0, 0, 0 },  // 6
			{ 0, 1, 1, 0, 0, 0, 0, 0, 0 },  // 7
			{ 1, 0, 0, 0, 1, 0, 0, 0, 0 } };// 8


      Graph1 G = new Graph1(conn);

      G.clearVisited();
      G.dfs(0);

   }
}
//-------------------------------------------------------------------------------------------------------------

//iterative solution
import java.util.*;

public class Graph2
{
   /* ------------------------------------------
      Data structure used to represent a graph
      ------------------------------------------ */
   int[][]  adjMatrix;
   int      rootNode = 0;
   int      NNodes;

   boolean[] visited; 

   /* -------------------------------
      Construct a graph of N nodes
      ------------------------------- */
   Graph2(int N)
   {
      NNodes = N;
      adjMatrix = new int[N][N];
      visited = new boolean[N];
   }

   Graph2(int[][] mat)
   {
      int i, j;

      NNodes = mat.length;

      adjMatrix = new int[NNodes][NNodes];
      visited = new boolean[NNodes];


      for ( i=0; i < NNodes; i++)
         for ( j=0; j < NNodes; j++)
            adjMatrix[i][j] = mat[i][j];
   }

   public void dfs()
   {
      //DFS uses Stack data structure

      Stack<Integer> s = new Stack<Integer>();

      s.push(rootNode);
      visited[rootNode] = true;

      printNode(rootNode);

      while( !s.isEmpty() )
      {
         int n, child;

         n = (s.peek()).intValue();

         child = getUnvisitedChildNode(n);

         if ( child != -1 )
         {
            visited[child] = true;

            printNode(child);

            s.push(child);
         }
         else
         {
            s.pop();
         }
      }

      clearVisited();      //Clear visited property of nodes
   }


   int getUnvisitedChildNode(int n)
   {
      int j;

      for ( j = 0; j < NNodes; j++ )
      {
	 if ( adjMatrix[n][j] > 0 )
         {
	    if ( ! visited[j] )
               return(j);
         }
      }

      return(-1);
   }

   void clearVisited()
   {
      int i;

      for (i = 0; i < visited.length; i++)
         visited[i] = false;
   }

   void printNode(int n)
   {
      System.out.println(n);
   }
}


public class TestProg2
{

   public static void main(String[] args)
   {
//                        0  1  2  3  4  5  6  7  8
// ===================================================
      int[][] conn = {  { 0, 1, 0, 1, 0, 0, 0, 0, 1 },  // 0
			{ 1, 0, 0, 0, 0, 0, 0, 1, 0 },  // 1
			{ 0, 0, 0, 1, 0, 1, 0, 1, 0 },  // 2
			{ 1, 0, 1, 0, 1, 0, 0, 0, 0 },  // 3
			{ 0, 0, 0, 1, 0, 0, 0, 0, 1 },  // 4
			{ 0, 0, 1, 0, 0, 0, 1, 0, 0 },  // 5
			{ 0, 0, 0, 0, 0, 1, 0, 0, 0 },  // 6
			{ 0, 1, 1, 0, 0, 0, 0, 0, 0 },  // 7
			{ 1, 0, 0, 0, 1, 0, 0, 0, 0 } };// 8


      Graph2 G = new Graph2(conn);

      G.clearVisited();
      G.dfs();

   }
}

//-------------------------------------------------------------------------------------------------------------------------

