for _ in range(int(input())):
    n = int(input())
    parent_list = [0] * (n + 1)
    for i in range(n - 1):
        parent, child = map(int, input().split())
        parent_list[child] = parent
    t1, t2 = map(int, input().split())
    #print(parent_list)
    t1_parent_list = [t1]
    while parent_list[t1] != 0:
        t1 = parent_list[t1]
        t1_parent_list.append(t1)
    t2_parent_list = [t2]
    while parent_list[t2] != 0:
        t2 = parent_list[t2]
        t2_parent_list.append(t2)
    
    t1_parent_list.reverse()
    t2_parent_list.reverse()
    
    #print(t1_parent_list)
    #print(t2_parent_list)

    for i in range(len(t1_parent_list)):
        #print(i)
        if i > len(t2_parent_list) - 1:
            print(t1_parent_list[i - 1])
            break
        if t1_parent_list[i] != t2_parent_list[i]:
            print(t1_parent_list[i - 1])
            break

    else:
        print(t1_parent_list[-1])
