import argparse
import cmath
import math
from ast import literal_eval


def parse_ctuple(ctuple):
    return literal_eval(ctuple)


parser = argparse.ArgumentParser()
parser.add_argument("ctuple", help="Tuple with two numbers.", type=str)
group = parser.add_mutually_exclusive_group()
group.add_argument('-c2p', '--cartesian2polar', action='store_true',
                   help="Converts entered complex nuber from cartesian to polar representation")
group.add_argument('-p2c', '--polar2cartesian', action='store_true',
                   help="Converts entered complex nuber from polar to cartesian representation. The phase should be entered in degrees")
args = parser.parse_args()

tup1, tup2 = parse_ctuple(args.ctuple)

if args.cartesian2polar:
    cnum = complex(tup1, tup2)
    polar_representation = cmath.polar(cnum)
    print("Polar representation of entered complex number " +
          str(polar_representation))

if args.polar2cartesian:
    tup2 = math.radians(tup2)
    cartesian_representation = cmath.rect(tup1, tup2)
    print("Cartesian representation of entered complex number " +
          str(cartesian_representation))
