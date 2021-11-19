/*
    ���ڳ���Ϊ N �Ĵ�����ת���ַ����飬���ǿ��Թ۲췴תǰ���±�ı仯��
    ���跴תǰ�ַ�����Ϊ s[0] s[1] s[2] ... s[N - 1]��
    ��ô��ת���ַ�����Ϊ s[N - 1] s[N - 2] ... s[0]��
    �ȽϷ�תǰ���±�仯�����׵ó� s[i] ���ַ��� s[N - 1 - i] ���ַ������˽����Ĺ��ɣ�
    ������ǿ��Եó�����˫ָ��Ľⷨ��
        �� left ָ���ַ�������Ԫ�أ�right ָ���ַ�����βԪ�ء�
        �� left < right��
        ���� s[left] �� s[right]��
        left ָ������һλ���� left = left + 1��
        right ָ������һλ���� right = right - 1��
        �� left >= right����ת�����������ַ����鼴�ɡ�
*/

void reverseString(char* s, int sSize){
    for (int left = 0, right = sSize - 1; left < right; left++, right--) {
        int temp = s[left];
        s[left] = s[right];
        s[right] = temp;
    }

    return 0;
}