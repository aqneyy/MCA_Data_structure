
#include <stdio.h>
#define MAX 20

struct Edge
{
    int u, v, w;
};

int parent[MAX];

// Find function
int find(int i)
{
    while (parent[i] != i)
    {
        i = parent[i];
    }
    return i;
}

// Union function
void union_set(int i, int j)
{
    int a = find(i);
    int b = find(j);

    parent[a] = b;
}

int main()
{
    struct Edge edges[MAX];
    int n, e;
    int totalcost = 0;

    // Read number of vertices and edges
    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter number of edges: ");
    scanf("%d", &e);

    // Read edges
    printf("Enter each edge (u v weight):\n");

    for (int i = 0; i < e; i++)
    {
        scanf("%d%d%d",
              &edges[i].u,
              &edges[i].v,
              &edges[i].w);
    }

    // Sort edges using Bubble Sort
    for (int i = 0; i < e - 1; i++)
    {
        for (int j = 0; j < e - i - 1; j++)
        {
            if (edges[j].w > edges[j + 1].w)
            {
                struct Edge temp = edges[j];

                edges[j] = edges[j + 1];
                edges[j + 1] = temp;
            }
        }
    }

    // Initialize parent array
    for (int i = 0; i < n; i++)
    {
        parent[i] = i;
    }

    printf("\nEdges in the minimum spanning tree:\n");

    int count = 0;

    // Kruskal's Algorithm
    for (int i = 0; i < e && count < n - 1; i++)
    {
        int u = edges[i].u;
        int v = edges[i].v;
        int w = edges[i].w;

        int pu = find(u);
        int pv = find(v);

        if (pu != pv)
        {
            printf("%d - %d : %d\n", u, v, w);

            totalcost += w;

            union_set(pu, pv);

            count++;
        }
    }

    // Display result
    if (count == n - 1)
    {
        printf("Total cost of MST = %d\n", totalcost);
    }
    else
    {
        printf("Minimum spanning tree does not exist\n");
    }

    return 0;
}
