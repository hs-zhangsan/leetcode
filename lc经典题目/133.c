/*
    方法一：深度优先搜索

    思路

    对于本题而言，我们需要明确图的深拷贝是在做什么，
    对于一张图而言，它的深拷贝即构建一张与原图结构，值均一样的图，但是其中的节点不再是原来图节点的引用。
    因此，为了深拷贝出整张图，我们需要知道整张图的结构以及对应节点的值。
    
    由于题目只给了我们一个节点的引用，因此为了知道整张图的结构以及对应节点的值，我们需要从给定的节点出发，进行「图的遍历」，并在遍历的过程中完成图的深拷贝。
    
    为了避免在深拷贝时陷入死循环，我们需要理解图的结构。
    对于一张无向图，任何给定的无向边都可以表示为两个有向边，即如果节点 A 和节点 B 之间存在无向边，则表示该图具有从节点 A 到节点 B 的有向边和从节点 B 到节点 A 的有向边。
    
    为了防止多次遍历同一个节点，陷入死循环，我们需要用一种数据结构记录已经被克隆过的节点。
    
    
    算法
    
    1.使用一个哈希表存储所有已被访问和克隆的节点。
    哈希表中的 key 是原始图中的节点，value 是克隆图中的对应节点。

    2.从给定节点开始遍历图。如果某个节点已经被访问过，则返回其克隆图中的对应节点。

    3.如果当前访问的节点不在哈希表中，则创建它的克隆节点并存储在哈希表中。
    注意：在进入递归之前，必须先创建克隆节点并保存在哈希表中。
    如果不保证这种顺序，可能会在递归中再次遇到同一个节点，再次遍历该节点时，陷入死循环。

    4.递归调用每个节点的邻接点。
    每个节点递归调用的次数等于邻接点的数量，每一次调用返回其对应邻接点的克隆节点，最终返回这些克隆邻接点的列表，将其放入对应克隆节点的邻接表中。
    这样就可以克隆给定的节点和其邻接点。
*/
struct Node** visited;

struct Node* dfs(struct Node* s) {
    if (s == NULL) {
        return NULL;
    }

    // 如果该节点已经被访问过了，则直接从哈希表中取出对应的克隆节点返回
    if (visited[s->val]) {
        return visited[s->val];
    }

    // 克隆节点，注意到为了深拷贝我们不会克隆它的邻居的列表
    struct Node* cloneNode = (struct Node*)malloc(sizeof(struct Node));
    cloneNode->val = s->val;
    cloneNode->numNeighbors = s->numNeighbors;

    // 哈希表存储
    visited[cloneNode->val] = cloneNode;
    cloneNode->neighbors = (struct Node**)malloc(sizeof(struct Node*) * cloneNode->numNeighbors);

    // 遍历该节点的邻居并更新克隆节点的邻居列表
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
    方法二：广度优先遍历

    
    思路
    
    同样，我们也可以用广度优先搜索来进行「图的遍历」。
    
    方法一与方法二的区别仅在于搜索的方式。
    深度优先搜索以深度优先，广度优先搜索以广度优先。
    这两种方法都需要借助哈希表记录被克隆过的节点来避免陷入死循环。
    

    算法
    
    1.使用一个哈希表 visited 存储所有已被访问和克隆的节点。
    哈希表中的 key 是原始图中的节点，value 是克隆图中的对应节点。

    2.将题目给定的节点添加到队列。克隆该节点并存储到哈希表中。
    
    3.每次从队列首部取出一个节点，遍历该节点的所有邻接点。
    如果某个邻接点已被访问，则该邻接点一定在 visited 中，那么从 visited 获得该邻接点，否则创建一个新的节点存储在 visited 中，并将邻接点添加到队列。
    将克隆的邻接点添加到克隆图对应节点的邻接表中。
    重复上述操作直到队列为空，则整个图遍历结束。
*/
struct Node** visited;
int* state;  //数组存放结点状态 0：结点未创建 1：仅创建结点 2：结点已创建并已填入所有内容

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
        // 如果没有被访问过，就克隆并存储在哈希表中
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

    // 将题目给定的节点添加到队列
    struct Node *QUEUE[101], *p;
    int head = -1, eneighbor = -1, i, flag[101];

    visited = (struct Node**)malloc(sizeof(struct Node*) * 101);
    memset(visited, 0, sizeof(struct Node*) * 101);
    state = (int*)malloc(sizeof(int) * 101);
    memset(state, 0, sizeof(int) * 101);
    memset(flag, 0, sizeof(int) * 101);

    // 克隆第一个节点并存储到哈希表中
    QUEUE[++eneighbor] = s;

    // 广度优先搜索
    while (head != eneighbor) {
        // 取出队列的头节点
        p = QUEUE[++head];
        // 遍历该节点的邻居
        bfs(p);
        for (i = 0; i < p->numNeighbors; i++) {
            if (!flag[p->neighbors[i]->val]) {
                // 将邻居节点加入队列中
                QUEUE[++eneighbor] = p->neighbors[i];
                flag[p->neighbors[i]->val] = 1;
            }
        }
    }

    return visited[s->val];
}