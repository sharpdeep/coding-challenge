##问题：
用两个栈来实现一个队列，完成队列的Push和Pop操作。 队列中的元素为int类型。

##思路：
栈是先入后出的数据结构，而队列是一种先入先出的结构。用两个栈，一个可以作为入队的栈(stack1)，另一个作为出队的栈(stack2)。那么push和pop处理如下：

* **Push**：直接入stack1；
* **Pop**： 
	* 如果stack2中有元素的话，那么出栈返回；
	* 如果没有的话，那么将stack1的元素**逐个**出栈并入stack2，然后再从stack2中出栈返回；
	
##Code:
*因为Python并没有堆或者栈的数据类型，当然用List是可以实现的。但是这里就用Java代码来实现了！*

```Java
import java.util.Stack;
 
class solution {
    Stack<Integer> stack1 = new Stack<Integer>();
    Stack<Integer> stack2 = new Stack<Integer>();
	
    public void push(int node) {
        stack1.push(node);
    }
     
    public int pop() {
        if(stack2.empty()){
            while(!stack1.empty()){
                stack2.push(stack1.pop());
            }
        }
        return stack2.pop();
    }
	
	public static void main(String[] args){
		solution s = new solution();
		
		for(int i = 0; i < 5; i++){
			s.push(i);
		}
		
		for(int i = 0; i < 5; i++){
			System.out.println(s.pop()+"\n");
		}
	}
}

```