def leveshtein_distance(a, b, cost_delete, cost_insert, cost_replace):
    n = len(b)
    dp1, dp2 = [0] * (n + 1), [0] * (n + 1)
    for i in range(n + 1):
        dp1[i] = i * cost_insert
    for i in range(len(a)):
        dp2[0] = (i + 1) * cost_delete
        for j in range(n):
            del_cost, ins_cost, rep_cost = dp1[j + 1] + cost_delete, dp2[j] + cost_insert, None
            if a[i] == b[i]:
                rep_cost = dp1[j]
            else:
                rep_cost = dp1[j] + cost_replace
            dp2[j + 1] = min(del_cost, min(ins_cost, rep_cost))
        dp1 = [*dp2]
    return dp1[n]


print(leveshtein_distance("intention", "execution", 1, 2, 4))
