class Solution:
    def maxStability(self, n, edges, k):

        def make_uf():
            parent = list(range(n))
            rank = [0] * n
            return parent, rank

        def find(parent, x):
            while parent[x] != x:
                parent[x] = parent[parent[x]]
                x = parent[x]
            return x

        def union(parent, rank, x, y):
            px, py = find(parent, x), find(parent, y)
            if px == py:
                return False
            if rank[px] < rank[py]:
                px, py = py, px
            parent[py] = px
            if rank[px] == rank[py]:
                rank[px] += 1
            return True

        def boruvka_rounds(parent, rank, pool):
            total_merges = 0
            while True:
                cheapest = {}
                for i, (u, v) in enumerate(pool):
                    pu = find(parent, u)
                    pv = find(parent, v)
                    if pu == pv:
                        continue
                    if pu not in cheapest:
                        cheapest[pu] = i
                    if pv not in cheapest:
                        cheapest[pv] = i
                if not cheapest:
                    break
                seen = set()
                merges = 0
                for comp, idx in cheapest.items():
                    if idx in seen:
                        continue
                    seen.add(idx)
                    u, v = pool[idx]
                    if union(parent, rank, u, v):
                        merges += 1
                if merges == 0:
                    break
                total_merges += merges
            return total_merges

        def can_achieve(lim):
            parent, rank = make_uf()
            for u, v, s, must in edges:
                if must == 1:
                    if s < lim:
                        return False
                    if not union(parent, rank, u, v):
                        return False
            free_pool = [(u, v) for u, v, s, must in edges
                         if must == 0 and s >= lim]
            boruvka_rounds(parent, rank, free_pool)
            upg_pool = [(u, v) for u, v, s, must in edges
                        if must == 0 and 2 * s >= lim and s < lim]
            upgrades_used = boruvka_rounds(parent, rank, upg_pool)
            if upgrades_used > k:
                return False
            root = find(parent, 0)
            for i in range(1, n):
                if find(parent, i) != root:
                    return False
            return True

        # Build candidate list
        candidates = set()
        for u, v, s, must in edges:
            candidates.add(s)
            if must == 0:
                candidates.add(2 * s)

        # Binary search over sorted candidates instead of linear scan
        candidates = sorted(candidates)  # ascending
        lo, hi = 0, len(candidates) - 1
        ans = -1
        while lo <= hi:
            mid = (lo + hi) // 2
            if can_achieve(candidates[mid]):
                ans = candidates[mid]
                lo = mid + 1   # try higher stability
            else:
                hi = mid - 1   # try lower stability

        return ans