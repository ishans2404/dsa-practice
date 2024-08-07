import sys
class Solution(object):
    def numberToWords(self, n):
        """
        :type num: int
        :rtype: str
        """
        if n == 0: return 'Zero'
        upto20 = ["", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"]
        tenPlaces = ["", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"]
        def digit2(n):
            if n<20: return upto20[n]
            else:
                tens = n // 10
                ones = n % 10
                if ones == 0: return tenPlaces[tens]
                else: return tenPlaces[tens] + ' ' + upto20[ones]
        def digit3(n):
            if not n: return ''
            if not n//100: return digit2(n)
            return upto20[n//100] + ' Hundred' + (' ' + digit2(n%100) if n%100 else '')
        
        bil = n // 1000000000
        mil = (n // 1000000) % 1000
        thou = (n // 1000) % 1000
        hund = n % 1000

        res = ''
        if bil:
            res += digit3(bil) + ' Billion'
        if mil:
            if res: res += ' '
            res += digit3(mil) + ' Million'
        if thou:
            if res: res += ' '
            res += digit3(thou) + ' Thousand'
        if hund:
            if res: res += ' '
            res += digit3(hund)

        res.strip()
        return res