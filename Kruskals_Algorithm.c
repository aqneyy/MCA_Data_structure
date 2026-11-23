
#include <stdio.h>
#define MAX 20

struct Edge
{
    int u, v, w;
};

int parent[MAX];

int find(int i)
{
    while (parent[i] != i)
    {
        i = parent[i];
    }
    return i;
}

void union_set(int i, int j)
{
    int a = find(i);
    int b = find(j);

    parent[a] = b;
}

int main()
{
    struct Edge edges[MAX], temp;
    int n, e;
    int i, j;
    int u, v, w;
    int pu, pv;
    int count = 0;
    int totalcost = 0;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter number of edges: ");
    scanf("%d", &e);

    printf("Enter each edge (u v weight):\n");

    for (i = 0; i < e; i++)
    {
        scanf("%d%d%d",
              &edges[i].u,
              &edges[i].v,
              &edges[i].w);
    }

   
    for (i = 0; i < e - 1; i++)
    {
        for (j = 0; j < e - i - 1; j++)
        {
            if (edges[j].w > edges[j + 1].w)
            {
                temp = edges[j];
                edges[j] = edges[j + 1];
                edges[j + 1] = temp;
            }
        }
    }

   
    for (i = 0; i < n; i++)
    {
        parent[i] = i;
    }

    printf("\nEdges in the minimum spanning tree:\n");

   
    for (i = 0; i < e && count < n - 1; i++)
    {
        u = edges[i].u;
        v = edges[i].v;
        w = edges[i].w;

        pu = find(u);
        pv = find(v);

        if (pu != pv)
        {
            printf("%d - %d : %d\n", u, v, w);

            totalcost = totalcost + w;

            union_set(pu, pv);

            count++;
        }
    }

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
