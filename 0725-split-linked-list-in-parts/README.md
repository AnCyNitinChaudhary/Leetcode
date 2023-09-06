<h2><a href="https://leetcode.com/problems/split-linked-list-in-parts/">725. Split Linked List in Parts</a></h2><h3>Medium</h3><hr><div speechify-initial-font-size="14px" style="font-size: 14px;"><p speechify-initial-font-size="14px" style="font-size: 14px;">Given the <code speechify-initial-font-size="13px" style="font-size: 13px;">head</code> of a singly linked list and an integer <code speechify-initial-font-size="13px" style="font-size: 13px;">k</code>, split the linked list into <code speechify-initial-font-size="13px" style="font-size: 13px;">k</code> consecutive linked list parts.</p>

<p speechify-initial-font-size="14px" style="font-size: 14px;">The length of each part should be as equal as possible: no two parts should have a size differing by more than one. This may lead to some parts being null.</p>

<p speechify-initial-font-size="14px" style="font-size: 14px;">The parts should be in the order of occurrence in the input list, and parts occurring earlier should always have a size greater than or equal to parts occurring later.</p>

<p speechify-initial-font-size="14px" style="font-size: 14px;">Return <em speechify-initial-font-size="14px" style="font-size: 14px;">an array of the </em><code speechify-initial-font-size="13px" style="font-size: 13px;">k</code><em speechify-initial-font-size="14px" style="font-size: 14px;"> parts</em>.</p>

<p speechify-initial-font-size="14px" style="font-size: 14px;">&nbsp;</p>
<p speechify-initial-font-size="14px" style="font-size: 14px;"><strong class="example" speechify-initial-font-size="14px" style="font-size: 14px;">Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/06/13/split1-lc.jpg" style="width: 400px; height: 134px; font-size: 14px;" speechify-initial-font-size="14px">
<pre speechify-initial-font-size="13px" style="font-size: 13px;"><strong speechify-initial-font-size="13px" style="font-size: 13px;">Input:</strong> head = [1,2,3], k = 5
<strong speechify-initial-font-size="13px" style="font-size: 13px;">Output:</strong> [[1],[2],[3],[],[]]
<strong speechify-initial-font-size="13px" style="font-size: 13px;">Explanation:</strong>
The first element output[0] has output[0].val = 1, output[0].next = null.
The last element output[4] is null, but its string representation as a ListNode is [].
</pre>

<p speechify-initial-font-size="14px" style="font-size: 14px;"><strong class="example" speechify-initial-font-size="14px" style="font-size: 14px;">Example 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/06/13/split2-lc.jpg" style="width: 600px; height: 60px; font-size: 14px;" speechify-initial-font-size="14px">
<pre speechify-initial-font-size="13px" style="font-size: 13px;"><strong speechify-initial-font-size="13px" style="font-size: 13px;">Input:</strong> head = [1,2,3,4,5,6,7,8,9,10], k = 3
<strong speechify-initial-font-size="13px" style="font-size: 13px;">Output:</strong> [[1,2,3,4],[5,6,7],[8,9,10]]
<strong speechify-initial-font-size="13px" style="font-size: 13px;">Explanation:</strong>
The input has been split into consecutive parts with size difference at most 1, and earlier parts are a larger size than the later parts.
</pre>

<p speechify-initial-font-size="14px" style="font-size: 14px;">&nbsp;</p>
<p speechify-initial-font-size="14px" style="font-size: 14px;"><strong speechify-initial-font-size="14px" style="font-size: 14px;">Constraints:</strong></p>

<ul speechify-initial-font-size="14px" style="font-size: 14px;">
	<li speechify-initial-font-size="14px" style="font-size: 14px;">The number of nodes in the list is in the range <code speechify-initial-font-size="13px" style="font-size: 13px;">[0, 1000]</code>.</li>
	<li speechify-initial-font-size="14px" style="font-size: 14px;"><code speechify-initial-font-size="13px" style="font-size: 13px;">0 &lt;= Node.val &lt;= 1000</code></li>
	<li speechify-initial-font-size="14px" style="font-size: 14px;"><code speechify-initial-font-size="13px" style="font-size: 13px;">1 &lt;= k &lt;= 50</code></li>
</ul>
</div>