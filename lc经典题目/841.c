/*
    ǰ��
    �� x �ŷ������� y �ŷ����Կ��ʱ�����ǾͿ��Դ� x �ŷ���ȥ�� y �ŷ��䡣
    ������ǽ��� n �����俴������ͼ�е� n ���ڵ㣬��ô������ϵ�Ϳ��Կ�����ͼ�е� x �ŵ㵽 y �ŵ��һ������ߡ�
    ����һ��������ͱ���˸���һ������ͼ��ѯ�ʴ� 0 �Žڵ�����Ƿ��ܹ��������еĽڵ㡣
*/

/*
    ����һ�������������

    ���ǿ���ʹ��������������ķ�ʽ��������ͼ��ͳ�ƿ��Ե���Ľڵ���������������� vis ��ǵ�ǰ�ڵ��Ƿ���ʹ����Է�ֹ�ظ����ʡ�
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
    �������������������
    
    ����Ҳ����ʹ�ù�����������ķ�ʽ��������ͼ��ͳ�ƿ��Ե���Ľڵ���������������� vis ��ǵ�ǰ�ڵ��Ƿ���ʹ����Է�ֹ�ظ����ʡ�
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