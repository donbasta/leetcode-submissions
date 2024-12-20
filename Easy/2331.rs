// Definition for a binary tree node.
// #[derive(Debug, PartialEq, Eq)]
// pub struct TreeNode {
//   pub val: i32,
//   pub left: Option<Rc<RefCell<TreeNode>>>,
//   pub right: Option<Rc<RefCell<TreeNode>>>,
// }
// 
// impl TreeNode {
//   #[inline]
//   pub fn new(val: i32) -> Self {
//     TreeNode {
//       val,
//       left: None,
//       right: None
//     }
//   }
// }
use std::rc::Rc;
use std::cell::RefCell;
impl Solution {
    pub fn evaluate_tree(root: Option<Rc<RefCell<TreeNode>>>) -> bool {
        match root {
            Some(x) => {
                match x.borrow().val {
                    0 => false,
                    1 => true,
                    2 => (Self::evaluate_tree(x.borrow().left.clone()) || Self::evaluate_tree(x.borrow().right.clone())),
                    3 => (Self::evaluate_tree(x.borrow().left.clone()) && Self::evaluate_tree(x.borrow().right.clone())),
                    _ => {assert!(false); return false;}
                }
            },
            None => {
                assert!(false);
                return false;
            }
        }
    }
}