// import java.util.LinkedList;
// must comment this before running
public class client {
    public static void main(String[] args) {
        linkedlist<Integer> ll = new linkedlist<>();        // generic code

        for (int i = 1; i <= 10; i++)
            ll.addLast(i * 10);
        System.out.println(ll);
        

        ll.addFirst(67);
        System.out.println(ll);

        System.out.println(ll.getAt(0));
        
        System.out.println(ll.getFirst());

        System.out.println(ll.getLast());

        System.out.println(ll.isEmpty());

        ll.removeAt(0);
        System.out.println(ll);

        ll.removeFirst();
        System.out.println(ll);

        ll.removeLast();
        System.out.println(ll);

        ll.reverseDataItrator();
        System.out.println(ll);

        ll.addLast(10);
        System.out.println(ll);

        ll.reverseList();
        System.out.println(ll);
    }
}