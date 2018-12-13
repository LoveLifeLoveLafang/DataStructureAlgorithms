/*
* **************************
* **************************
* ****** Linked Lists ******
* **************************
* **************************
* */

function ListNode(val) {
    this.val = val;
    this.next = null;
}

function RandomListNode(label) {
    this.label = label;
    this.next = this.random = null;
}

/*
*  链表逆序
*  206. reverse linked list
* */
var reverseList = function(head) {
  if (head === null)
      return head;

  var dummy = new ListNode(0);
  dummy.next = head;
  while(head.next != null) {
      cur = head.next;
      head.next = cur.next;
      cur.next = dummy.next;
      dummy.next = cur;
  }
  return dummy.next;
};

/*
*  链表逆序II
*  92. reverse Linked list II
**/
var reverseBetween = function(head, m, n) {
  var dummy = new ListNode(0);
  dummy.next = head;
  var pre = dummy;
  var cur = head;
  var count = n - m;

  while(m > 1) {
      pre = pre.next;
      cur = cur.next;
      m--;
  }

  while(count > 0) {
      var p = cur.next;
      cur.next = p.next;
      p.next = pre.next;
      pre.next = p;
      count--;
  }
  return dummy.next;
};


/*
*  链表求交点
*  160. intersection of Two Linked Lists
* */
var getIntersectionNode = function(headA, headB) {
    if (headA === null || headB === null)
        return null;

    //init a map
    let mp = new Set();

    //traverse one of linkeds lists, store the node into map
    var cur = headA;
    while(cur !== null) {
        mp.add(cur);
        cur = cur.next;
    }
    //traverse the other linked  lists to find the same node
    cur = headB;
    while(cur !== null) {
        if (mp.has(cur) === true) {
            return cur;
        }
        cur = cur.next;
    }
    return null;
};

//辅助空间为O(1)
var getIntersectionNode1 = function(headA, headB) {
    if (headA === null || headB === null)
        return null;
    let alength = getLinkedListLen(headA);
    let blength = getLinkedListLen(headB);

    let acur = headA;
    let bcur = headB;

    if (alength > blength) {
        let n = alength - blength;
        while(n > 0) {
            acur = acur.next;
            n--;
        }
    } else {
        let n = blength - alength;
        while(n > 0) {
            bcur = bcur.next;
            n--;
        }
    }

    while(acur !== null && bcur !== null) {
        if (acur === bcur)
            return acur;
        acur = acur.next;
        bcur = bcur.next;
    }

    return null;
}

function getLinkedListLen(head) {
    if (head === null)
        return 0;
    let cur = head;
    let len = 0;
    while(cur !== null){
        cur = cur.next;
        len++;
    }
    return len;
}

/*
*  链表求环
*  141. Linked List Cycle
* */
var hasCycle = function(head) {
    if (head === null)
        return false;
    let s = new Set();

    let cur = head;

    while(cur !== null) {
        if (s.has(cur))
            return true;
        s.add(cur);
        cur = cur.next;
    }
    return false;
};

/*
*  链表划分
*  86. partition list
* */
var partition = function(head, x) {
    if (head === null)
        return head;

    let smallHead = new ListNode(0);
    let bigHead = new ListNode(0);
    let small = smallHead;
    let big = bigHead;

    while(head !== null) {
        let cur = new ListNode(head.val);
        head = head.next;
        if (cur.val < x) {
            small.next = cur;
            small = small.next;
        } else {
            big.next = cur;
            big = big.next;
        }
    }

    small.next = bigHead.next;
    return smallHead.next;
};

/*
*  复杂链表复制
*  138. Copy List with Random Pointer
* */
var copyRandomList = function(head) {
    if (head === null)
        return null;

    //第一步， 复制每个节点，并将新节点插入到其后
    let cur = head;
    while(cur !== null) {
        let node = new RandomListNode(cur.label);
        node.next = cur.next;
        cur.next = node;
        cur = cur.next.next;
    }

    //第二步， 补全random指针
    let pre = head;
    cur = head.next;
    while(cur !== null) {
        if (pre.random !== null) {
            cur.random = pre.random.next;
        }
        if (cur.next === null)
            break;
        pre = pre.next.next;
        cur = pre.next;
    }

    //第三步,  拆分成新的链表
    let dummy = new RandomListNode(0);
    let p = dummy;
    pre = head;
    cur = head.next;
    while(cur !== null) {
        pre.next = pre.next.next;
        pre = pre.next;
        cur.next = p.next;
        p.next = cur;
        p = p.next;
        if (pre === null)
            break;
        cur = pre.next;
    }
    return dummy.next;
};

/*
*  两个排序链表排序
*  21. Merge Two Sorted Lists
* */
var mergeTwoLists = function(l1, l2) {

    //首先， 判断是否有空链表存在
    if (l1 === null)
        return l2;
    if (l2 === null)
        return l1;

    //其次， 借助哨兵节点
    let dummy = new ListNode(0);
    let cur = dummy;
    while(l1 !== null && l2 !== null){
        if (l1.val < l2.val) {
            cur.next = l1;
            l1 = l1.next;
        } else {
            cur.next = l2;
            l2 = l2.next;
        }
        cur = cur.next;
    }

    if(l1 !== null)
        cur.next = l1;
    if(l2 !== null)
        cur.next = l2;
    return dummy.next;
};

/*
*  k个排序链表的排序
*  23. Merge k Sorted Lists
* */
var mergeKLists = function(lists) {
    
};

