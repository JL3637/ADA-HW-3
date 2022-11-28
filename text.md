# Homework 3
#### B10902033 林祐辰
<br>
References:<br>
Problem 1: B10902032 李沛宸<br>
Problem 2: B10902032 李沛宸<br>
Problem 3: B10902032 李沛宸<br>
Problem 4: B10902032 李沛宸<br>
Problem 5: B10902032 李沛宸<br>
Problem 6: B10902032 李沛宸<br>
<br>
Problem 5:<br>
(a) False, counterexample:<br>
<img src="./ada_6.jpg" style="zoom:15%" /><br>
(b) Ans: R13 Minquan W. Rd., Cost: 45$<br>
My method: First I guess that 台北車站 would be the answer, since it looks like the middle of the map. Next I find out that 淡水 
(c) Proof:<br>
1. Because every node in the graph has exactly one out-degree, so starting from any node -> go to the node it's pointing to -> new node -> go to the node it's pointing to .... This process can go forever, since every node has an out-degree.<br>
2. Because the sequence above is infinite, and the nodes in the graph are finite. So we can easily find out that there must be a node that appears at least twice in the sequence. (because the sequence > n)<br>
3. There exist a pointing cycle, since there exist at least two same node in the sequence.<br>