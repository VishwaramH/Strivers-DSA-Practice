from typing import Optional

class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution:
    def hasCycle(self, head: Optional[ListNode]) -> bool:
        slow, fast = head, head
        while fast and fast.next:
            slow = slow.next
            fast = fast.next.next
            if slow == fast:
                return True
        return False


# --- User Input ---
values = list(map(int, input("Enter linked list values (space-separated): ").split()))
cycle_pos = int(input("Enter cycle position (index to loop back to, -1 for no cycle): "))

# --- Build Linked List ---
nodes = [ListNode(v) for v in values]

for i in range(len(nodes) - 1):
    nodes[i].next = nodes[i + 1]

# Create cycle if valid position given
if cycle_pos != -1 and 0 <= cycle_pos < len(nodes):
    nodes[-1].next = nodes[cycle_pos]  # tail points back to cycle_pos index

# --- Call Method ---
sol = Solution()
result = sol.hasCycle(nodes[0] if nodes else None)
print(f"Has Cycle: {result}")