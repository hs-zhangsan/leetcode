/*
    ����һ�������������

    ˼·

    ���ڱ�����ԣ�������Ҫ��ȷͼ�����������ʲô��
    ����һ��ͼ���ԣ��������������һ����ԭͼ�ṹ��ֵ��һ����ͼ���������еĽڵ㲻����ԭ��ͼ�ڵ�����á�
    ��ˣ�Ϊ�����������ͼ��������Ҫ֪������ͼ�Ľṹ�Լ���Ӧ�ڵ��ֵ��
    
    ������Ŀֻ��������һ���ڵ�����ã����Ϊ��֪������ͼ�Ľṹ�Լ���Ӧ�ڵ��ֵ��������Ҫ�Ӹ����Ľڵ���������С�ͼ�ı����������ڱ����Ĺ��������ͼ�������
    
    Ϊ�˱��������ʱ������ѭ����������Ҫ���ͼ�Ľṹ��
    ����һ������ͼ���κθ���������߶����Ա�ʾΪ��������ߣ�������ڵ� A �ͽڵ� B ֮���������ߣ����ʾ��ͼ���дӽڵ� A ���ڵ� B ������ߺʹӽڵ� B ���ڵ� A ������ߡ�
    
    Ϊ�˷�ֹ��α���ͬһ���ڵ㣬������ѭ����������Ҫ��һ�����ݽṹ��¼�Ѿ�����¡���Ľڵ㡣
    
    
    �㷨
    
    1.ʹ��һ����ϣ��洢�����ѱ����ʺͿ�¡�Ľڵ㡣
    ��ϣ���е� key ��ԭʼͼ�еĽڵ㣬value �ǿ�¡ͼ�еĶ�Ӧ�ڵ㡣

    2.�Ӹ����ڵ㿪ʼ����ͼ�����ĳ���ڵ��Ѿ������ʹ����򷵻����¡ͼ�еĶ�Ӧ�ڵ㡣

    3.�����ǰ���ʵĽڵ㲻�ڹ�ϣ���У��򴴽����Ŀ�¡�ڵ㲢�洢�ڹ�ϣ���С�
    ע�⣺�ڽ���ݹ�֮ǰ�������ȴ�����¡�ڵ㲢�����ڹ�ϣ���С�
    �������֤����˳�򣬿��ܻ��ڵݹ����ٴ�����ͬһ���ڵ㣬�ٴα����ýڵ�ʱ��������ѭ����

    4.�ݹ����ÿ���ڵ���ڽӵ㡣
    ÿ���ڵ�ݹ���õĴ��������ڽӵ��������ÿһ�ε��÷������Ӧ�ڽӵ�Ŀ�¡�ڵ㣬���շ�����Щ��¡�ڽӵ���б���������Ӧ��¡�ڵ���ڽӱ��С�
    �����Ϳ��Կ�¡�����Ľڵ�����ڽӵ㡣
*/
struct Node** visited;

struct Node* dfs(struct Node* s) {
    if (s == NULL) {
        return NULL;
    }

    // ����ýڵ��Ѿ������ʹ��ˣ���ֱ�Ӵӹ�ϣ����ȡ����Ӧ�Ŀ�¡�ڵ㷵��
    if (visited[s->val]) {
        return visited[s->val];
    }

    // ��¡�ڵ㣬ע�⵽Ϊ��������ǲ����¡�����ھӵ��б�
    struct Node* cloneNode = (struct Node*)malloc(sizeof(struct Node));
    cloneNode->val = s->val;
    cloneNode->numNeighbors = s->numNeighbors;

    // ��ϣ��洢
    visited[cloneNode->val] = cloneNode;
    cloneNode->neighbors = (struct Node**)malloc(sizeof(struct Node*) * cloneNode->numNeighbors);

    // �����ýڵ���ھӲ����¿�¡�ڵ���ھ��б�
    for (int i = 0; i < cloneNode->numNeighbors; i++) {
        cloneNode->neighbors[i] = dfs(s->neighbors[i]);
    }
    return cloneNode;
}

struct Node* cloneGraph(struct Node* s) {
    visited = (struct Node**)malloc(sizeof(struct Node*) * 101);
    memset(visited, 0, sizeof(struct Node*) * 101);
    return dfs(s);
}


/*
    ��������������ȱ���

    
    ˼·
    
    ͬ��������Ҳ�����ù���������������С�ͼ�ı�������
    
    ����һ�뷽��������������������ķ�ʽ��
    �������������������ȣ�������������Թ�����ȡ�
    �����ַ�������Ҫ������ϣ���¼����¡���Ľڵ�������������ѭ����
    

    �㷨
    
    1.ʹ��һ����ϣ�� visited �洢�����ѱ����ʺͿ�¡�Ľڵ㡣
    ��ϣ���е� key ��ԭʼͼ�еĽڵ㣬value �ǿ�¡ͼ�еĶ�Ӧ�ڵ㡣

    2.����Ŀ�����Ľڵ���ӵ����С���¡�ýڵ㲢�洢����ϣ���С�
    
    3.ÿ�δӶ����ײ�ȡ��һ���ڵ㣬�����ýڵ�������ڽӵ㡣
    ���ĳ���ڽӵ��ѱ����ʣ�����ڽӵ�һ���� visited �У���ô�� visited ��ø��ڽӵ㣬���򴴽�һ���µĽڵ�洢�� visited �У������ڽӵ���ӵ����С�
    ����¡���ڽӵ���ӵ���¡ͼ��Ӧ�ڵ���ڽӱ��С�
    �ظ���������ֱ������Ϊ�գ�������ͼ����������
*/
struct Node** visited;
int* state;  //�����Ž��״̬ 0�����δ���� 1����������� 2������Ѵ�������������������

void bfs(struct Node* s) {
    if (visited[s->val] && state[s->val] == 2) {
        return;
    }
    struct Node* neighbor;
    if (visited[s->val]) {
        neighbor = visited[s->val];
        neighbor->val = s->val;
        neighbor->numNeighbors = s->numNeighbors;
        neighbor->neighbors = (struct Node**)malloc(sizeof(struct Node*) * neighbor->numNeighbors);
    } else {
        // ���û�б����ʹ����Ϳ�¡���洢�ڹ�ϣ����
        neighbor = (struct Node*)malloc(sizeof(struct Node));
        neighbor->val = s->val;
        neighbor->numNeighbors = s->numNeighbors;
        neighbor->neighbors = (struct Node**)malloc(sizeof(struct Node*) * neighbor->numNeighbors);
        visited[s->val] = neighbor;
    }
    for (int i = 0; i < neighbor->numNeighbors; i++) {
        if (visited[s->neighbors[i]->val]) {
            neighbor->neighbors[i] = visited[s->neighbors[i]->val];
        } else {
            visited[s->neighbors[i]->val] = (struct Node*)malloc(sizeof(struct Node));
            state[s->neighbors[i]->val] = 1;
            neighbor->neighbors[i] = visited[s->neighbors[i]->val];
        }
    }
    state[neighbor->val] = 2;
}

struct Node* cloneGraph(struct Node* s) {
    if (s == NULL) {
        return NULL;
    }

    // ����Ŀ�����Ľڵ���ӵ�����
    struct Node *QUEUE[101], *p;
    int head = -1, eneighbor = -1, i, flag[101];

    visited = (struct Node**)malloc(sizeof(struct Node*) * 101);
    memset(visited, 0, sizeof(struct Node*) * 101);
    state = (int*)malloc(sizeof(int) * 101);
    memset(state, 0, sizeof(int) * 101);
    memset(flag, 0, sizeof(int) * 101);

    // ��¡��һ���ڵ㲢�洢����ϣ����
    QUEUE[++eneighbor] = s;

    // �����������
    while (head != eneighbor) {
        // ȡ�����е�ͷ�ڵ�
        p = QUEUE[++head];
        // �����ýڵ���ھ�
        bfs(p);
        for (i = 0; i < p->numNeighbors; i++) {
            if (!flag[p->neighbors[i]->val]) {
                // ���ھӽڵ���������
                QUEUE[++eneighbor] = p->neighbors[i];
                flag[p->neighbors[i]->val] = 1;
            }
        }
    }

    return visited[s->val];
}