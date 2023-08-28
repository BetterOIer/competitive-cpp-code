from cyaron import *

for id in range(1, 21):
    test_data = IO(file_prefix="data_", data_id=id)
    # 先把这几个变量定义了以避免作用域问题    
    MAXN = 0
    MAXM = 0
    MAXW = 0

    if id <= 5:
        MAXN = 1000
        MAXM = 2000
        MAXW = 300
    elif id <= 10: # 即 C++ 中的 else if
        MAXN = 20000
        MAXM = 50000
        MAXW = 500
    else:
        MAXN = int(1e6) # 不要把 C++ 的 (int)1e6 带到这里来！
        MAXM = int(5e6)
        MAXW = 500
    n = randint(500, MAXN) # 保证最低数据强度
    m = randint(n - 1, MAXM) # DAG 的性质，边数大于等于节点数-1
    graph = Graph.DAG(n, m) # n 点 m 边的 DAG
    test_data.writeln(n, m)
    test_data.writeln(graph)
    test_data.output_gen("假装这是标程地址")