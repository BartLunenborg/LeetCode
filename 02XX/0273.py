class Solution(object):
    num_to_words = {
        1: "One",
        2: "Two",
        3: "Three",
        4: "Four",
        5: "Five",
        6: "Six",
        7: "Seven",
        8: "Eight",
        9: "Nine",
        10: "Ten",
        11: "Eleven",
        12: "Twelve",
        13: "Thirteen",
        14: "Fourteen",
        15: "Fifteen",
        16: "Sixteen",
        17: "Seventeen",
        18: "Eighteen",
        19: "Nineteen",
        20: "Twenty",
        30: "Thirty",
        40: "Forty",
        50: "Fifty",
        60: "Sixty",
        70: "Seventy",
        80: "Eighty",
        90: "Ninety",
        100: "Hundred",
        1_000: "Thousand",
        1_000_000: "Million",
        1_000_000_000: "Billion",
    }

    geq_100 = {100, 1_000, 1_000_000, 1_000_000_000}

    def numberToWords(self, num):
        if num == 0:
            return "Zero"

        words = []
        divisor = 1_000_000_000
        while num:
            if num <= 20:
                words.append(f"{self.num_to_words[num]}")
                break

            if divisor not in self.num_to_words:
                divisor //= 10
                continue

            quotient, remainder = divmod(num, divisor)
            if quotient > 0:
                if (
                    quotient * divisor in self.num_to_words
                    and quotient * divisor not in self.geq_100
                ):
                    words.append(f"{self.num_to_words[quotient * divisor]}")
                else:
                    words.append(
                        f"{self.numberToWords(quotient)} {self.num_to_words[divisor]}"
                    )
            num = remainder
            divisor //= 10
        return " ".join(words)
