# Queues: A Tale of Two Stacks

https://www.hackerrank.com/challenges/ctci-queue-using-two-stacks/problem

This one was quite interesting.  I got it working by re-creating both stacks every time a push came in, but obviously this creates redundancy, and some of the test cases were failing due to timeouts.  Both stacks share numbers.

My lunch was finished, so I put this aside and decided to try again the next day (today).  Last night I thought about a good way to achieve this.  Basically we use the second (or 'oldest on top') stack as a temporary holding container for incoming values.

So, we put the values in that stack every time a push comes in.  They would be sorted like this.... I'll use sequential numbers to illustrate better.

| Oldest        |
| ------------- |
| 1             |
| 2             |
| 3             |

Now when we want to pop or top (read or remove), we will create the newest on top stack by taking the bottom values, one by one, off of the oldest on top stack.

We would end up with this....

| Newest        |
| ------------- |
| 3             |
| 2             |
| 1             |

Let's say we pop through those, but in the meantime we have added numbers 4, 5, 6 and 7 to the oldest.  We would have this...

| Oldest        |
| ------------- |
| 4             |
| 5             |
| 6             |
| 7             |

All we have to do is create the newest on top stack again, and pop or top (delete or read) accordingly.

We would end up with this...

| Newest        |
| ------------- |
| 7             |
| 6             |
| 5             |
| 4             |

So, every time you call pop() or front() from the queue you are going to want to check if the newest on top stack has anything in it.  If it doesn't, you'll have to build it.

Doing this made my solution pass for all test cases, it uses less memory, and traverses the stacks way less (we're not re-creating stacks every time we push to the queue)