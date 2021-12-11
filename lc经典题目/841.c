/*
    前言
    当 x 号房间中有 y 号房间的钥匙时，我们就可以从 x 号房间去往 y 号房间。
    如果我们将这 n 个房间看成有向图中的 n 个节点，那么上述关系就可以看作是图中的 x 号点到 y 号点的一条有向边。
    这样一来，问题就变成了给定一张有向图，询问从 0 号节点出发是否能够到达所有的节点。
*/

/*
    方法一：深度优先搜索

    我们可以使用深度优先搜索的方式遍历整张图，统计可以到达的节点个数，并利用数组 vis 标记当前节点是否访问过，以防止重复访问。
*/
int num;

void dfs(int** rooms, int* roomsColSize, int* vis, int x) {
    vis[x] = true;
    num++;
    for (int i = 0; i < roomsColSize[x]; i++) {
        if (!vis[rooms[x][i]]) {
            dfs(rooms, roomsColSize, vis, rooms[x][i]);
        }
    }
}

bool canVisitAllRooms(int** rooms, int roomsSize, int* roomsColSize) {
    int vis[roomsSize];
    memset(vis, 0, sizeof(vis));
    num = 0;
    dfs(rooms, roomsColSize, vis, 0);
    return num == roomsSize;
}


/*
    方法二：广度优先搜索
    
    我们也可以使用广度优先搜索的方式遍历整张图，统计可以到达的节点个数，并利用数组 vis 标记当前节点是否访问过，以防止重复访问。
*/
bool canVisitAllRooms(int** rooms, int roomsSize, int* roomsColSize) {
    int vis[roomsSize], que[roomsSize];
    memset(vis, 0, sizeof(vis));
    int left = 0, right = 1, num = 0;
    vis[0] = true;
    que[0] = 0;
    while (left < right) {
        int x = que[left++];
        num++;
        for (int i = 0; i < roomsColSize[x]; i++) {
            if (!vis[rooms[x][i]]) {
                vis[rooms[x][i]] = true;
                que[right++] = rooms[x][i];
            }
        }
    }
    return num == roomsSize;
}