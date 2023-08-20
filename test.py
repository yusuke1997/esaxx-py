import unittest
from io import StringIO
from esa import esaxx

class TestEsaxx(unittest.TestCase):

    def test_abracadabra(self):
        # 期待される出力を設定
        expected_SA = [10, 7, 0, 3, 5, 8, 1, 4, 6, 9, 2]
        expected_L = [1, 0, 5, 9, 0, 0, 3, 0, 0, 0, 2]
        expected_R = [3, 5, 7, 11, 11, 1, 0, 1, 0, 0, 0]
        expected_D = [4, 1, 3, 2, 0, 0, 0, 0, 0, 0, 0]
        expected_node_num = 5

        T = 'abracadabra'
        SA = [0]*len(T)
        L = [0]*len(T)
        R = [0]*len(T)
        D = [0]*len(T)
        k = 0x100
        node_num = 0

        # esaxx関数を呼び出し
        node_num = esaxx(T, SA, L, R, D, len(T), k, node_num)

        # アサーションを使用して期待される出力と実際の出力を比較
        self.assertEqual(SA, expected_SA)
        self.assertEqual(L, expected_L)
        self.assertEqual(R, expected_R)
        self.assertEqual(D, expected_D)
        self.assertEqual(node_num, expected_node_num)


if __name__ == '__main__':
    unittest.main()
