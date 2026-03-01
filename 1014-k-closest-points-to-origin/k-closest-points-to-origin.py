class Solution:
    def kClosest(self, points, k):

        # Helper: squared Euclidean distance from origin
        # We use squared distance to avoid floating point
        # (sqrt is not needed for comparison, squaring preserves order)
        def dist(p):
            return p[0] * p[0] + p[1] * p[1]

        # Helper: find the median of a small group (size <= 7)
        # Sort the group by distance and return the middle element
        def median_of_group(group):
            group.sort(key=dist)
            return group[len(group) // 2]

        # Core recursive function: linear-time selection with group size 7
        # Returns the k points with the smallest distances from the origin
        def k_closest_neighbors(pts, k):

            # Base case: if the list is small, sort and return first k
            if len(pts) <= 7:
                pts.sort(key=dist)
                return pts[:k]

            # Step 1: Divide pts into groups of 7
            groups = [pts[i : i + 7] for i in range(0, len(pts), 7)]

            # Step 2: Find the median of each group
            medians = [median_of_group(g) for g in groups]

            # Step 3: Recursively find the median of medians (our pivot)
            # This guarantees a good split -- at most 5n/7 elements on either side
            mid = len(medians) // 2
            pivot_list = k_closest_neighbors(medians, mid + 1)
            pivot = pivot_list[-1]        # last of the returned list = median of medians
            pivot_dist = dist(pivot)

            # Step 4: Partition all points into three groups around pivot distance
            low     = [p for p in pts if dist(p) <  pivot_dist]  # closer than pivot
            mid_pts = [p for p in pts if dist(p) == pivot_dist]  # same as pivot
            high    = [p for p in pts if dist(p) >  pivot_dist]  # farther than pivot

            # Step 5: Recurse only on the partition that contains the k-th element
            if k <= len(low):
                # All k closest points are strictly in low
                return k_closest_neighbors(low, k)
            elif k <= len(low) + len(mid_pts):
                # low is not enough; fill the remainder from mid_pts
                return low + mid_pts[: k - len(low)]
            else:
                # Need all of low and mid_pts, plus some from high
                return (low + mid_pts
                        + k_closest_neighbors(high, k - len(low) - len(mid_pts)))

        return k_closest_neighbors(points, k)