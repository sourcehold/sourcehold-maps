import unittest

# logging.basicConfig(level = logging.DEBUG)

if __name__ == '__main__':
    test_suite = unittest.TestLoader().discover('.')
    unittest.TextTestRunner(descriptions=True, verbosity=2).run(test_suite)
