/**
 * @author ：YangChen
 * @date ：Created in 2019-09-05 19:28
 * @description：
 * @modified By：
 * @version:
 */
public class DayTwoSoultion{

    public static ListNode addTwoNumbers(ListNode l1,ListNode l2){

        ListNode head = new ListNode(-1);
        ListNode listNode = head;

        int p = 0;

        while (l1 != null || l2 != null){
            int m = l1 != null ? l1.val:0;
            int n = l2 != null ? l2.val:0;
            int num = m + n + p;

            p = num/10;

            listNode.next = new ListNode(num%10);

            listNode = listNode.next;


            l1 = l1!=null ? (l1.next != null ? l1.next:null) : null;
            l2 = l2!=null ? (l2.next != null ? l2.next:null) : null;


        }

        if(p>0){
            listNode.next = new ListNode(p);
        }


        return head.next;

    }


}