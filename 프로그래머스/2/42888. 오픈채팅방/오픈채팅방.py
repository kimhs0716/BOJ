def solution(record):
    name = dict()
    arr = []
    for r in record:
        a, b, *c = r.split()
        if a == "Change":
            name[b] = c[0]
        elif a == "Enter":
            name[b] = c[0]
            arr.append((a, b))
        else:
            arr.append((a, b))
    ret = []
    for a, b in arr:
        ret.append(name[b] + "님이 " + ["들어왔습니다.", "나갔습니다."][a=="Leave"])
    return ret