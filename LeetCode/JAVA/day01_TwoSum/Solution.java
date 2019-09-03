/**
 * @author ：YangChen
 * @date ：Created in 2019-09-03 21:57
 * @description：
 * @modified By：
 * @version:
 */
public class Solution {
    public static int[] twoSum(int[] nums, int target) {
        int[] result = new int[2];
        for(int i=0;i<nums.length;i++){
            for(int j=i+1;j<nums.length;j++){
                if(nums[i]+nums[j]==target){
                    result[0] = i;
                    result[1] = j;
                    break;
                }
            }
        }
        return result;
    }

    public static void main(String[] args) {
        int[] a = {2, 7, 11, 15};
        int res[] = twoSum(a,13);
        System.out.println("[" + res[0] +" , " + res[1] + "]");
    }
}
