/**
������ջ��ʵ��һ�����У���ɶ��е�Push��Pop������ �����е�Ԫ��Ϊint���͡�
**/
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
