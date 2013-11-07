$one = 123.4; /// done
$two = 42; /// done
$three = 42 - 8; /// done
$four = 1 + 2 * 3 - 4; /// done

const $test = $four; /// done
$three = $test + 2; /// done

//const $three = 3; /// done
//$three = int; /// fails - done

@five = [1, 2, 3, 4]; /// done
const @five2 = [$one, $two, 3, $four, 5, 6]; /// done
const @five3 = [$one + 31, $two, 3, $four - 7, 5, 6]; /// done
//@five2 = [1, 2]; /// fails - done
//@five4_fail = int; /// fails - done
@five4 = int[]; /// done
//const @five5 = float[]; /// fails - done
@five6 = void[]; /// done
//@five6 = float[]; /// fails - done
@five7 = [1, 2, 3]; /// done
@five7 = int[]; /// done
//@five7 = bool[]; /// fails - done
//@five7 = void[]; /// fails - done

@five = @five7; /// done
@five8 = [1, 2]; /// done
@five7 = @five8; /// done

@five[0] = $test; /// done
@five[1] = @five[2]; /// done

$six = @five[3]; /// done
$seven = @five[0] + 8; /// done

$eight = 42 + 1337 - @five[0] + 8; /// done
$nine = 42 + $six - @five[0] + 8; /// done

@five[0] = $six + @five[1]; /// done
@five[2] = $six + 42 - @five[3]; /// done

//@five = @five2; /// done - fails
//@five4 = [@five[0], @five[1] + 2, 13.37]; /// done - fails
@five4 = [@five[0], @five[1] + 2, 13, 37]; /// done

$ptr1 -> $two; /// done
$ptr2 <- $ptr1; /// done
//$ptr3 -> $ptr1; /// fails - done
//$ptr_c = &$one; /// fails - done
const $ptr_const -> $test; /// done
const $const_ptr_deref <- $ptr_const;

//$var_plus = +; /// fails - done
$var_plus2 = $one + $test; /// done

//FOO /// fails - done

alias PI = 3.14; /// done
//alias PI = 3.14; /// fails - done

alias AnswerOfLife = $two; /// done
//alias Fail = PI + $two; // fails - done

alias PIx2 = PI * 2; /// done
alias Pi = PI; /// done

$pi = PI; /// done

$ptr4 = null; /// done
$ptr1 = null; /// done
//$ptr2 = null; /// done

$str = "Hallo"; /// done
$str_ptr -> $str; /// done

//$ptr_x1 -> null; /// fails - done
//$ptr_x2 = $ptr4; /// fails - done
//$ptr_x22 = $ptr4 + 3; /// fails - done
//$ptr_x23 = $str_ptr; /// fails - done
//$ptr_x3 <- $ptr4; /// fails - done
//$ptr_x4 <- null; /// fails - done
//$ptr_exp = null + 4; /// fails - done
//$ptr_exp1 -> $pi + 4; /// fails - done
//$ptr_exp2 <- $ptr1 + 4; /// fails - done

//$if = false; /// fails - done
//$bool = true; /// fails - done
$cond = true; /// done
$cond = false; /// done
//$cond2 = true + false; /// fails - done

@cond_arr = [true, false/*, 1, 2*/]; /// done

//$cond = 0; /// fails -done
//$cond = 1; /// fails -done

//$number = true + 1 - false; /// fails - done

//$str_ptr = "foo"; /// fails - done

//$ptr1 -> $str; /// fails - done
//$ptr1 -> $one; /// fails - done

//$deref_ptr = $ptr1 + 42; /// fails - done

@ten = [null, $ptr1/*, 12*/]; /// done
@ten2 = [null]; /// done
//@ten3 = [null, $one]; /// done
//@eleven = null; /// fails - done
//@twelve = [+, -]; /// fails - done
//@twelve2 = [+ 1, - 2]; /// fails - done
@twelve3 = [2 + 1, 1 - 2]; /// done

$int_cast1 = cast<int>(42.5); /// done
$int_cast2 = cast<int>(PI) + cast<int>(PI); /// done
$int_cast2 = cast<int>(3.14) + cast<int>(PI); /// done
$int_cast2 = cast<int>(PI) + cast<int>(3.14); /// done
$int_cast3 = cast<int>($int_cast1) + cast<int>(3.14); /// done
$int_cast4 = cast<int>($int_cast1 - 3.14); /// done
$int_cast4 = cast<int>(3.14 * PI); /// done

alias I_Start = 1; /// done
$twelve = @twelve3[I_Start]; /// done

@cast_array1 = [42, PI, 1337, cast<int>(23)]; /// done
@cast_array2 = [42, cast<int>(PI), 1337, cast<int>(23)]; /// done
@cast_array3 = [42, cast<float>(PI), 1337, cast<int>(23)]; /// done

if (true) {
	$foo = 1;
}

if (false) {
	$bar = 2;
}

if ($pi == PI) {

}

if ($pi == 1) {

} else {

}

if ($pi == 2) {
	$foo = 2;
} else if ($pi > 3) {
	$bar = 3;
}

if (true && false) {
	$foo = 1;
}

if ($pi == 2 || $pi < 4) {
	$bar = 2;
}

for ($i in @five2) {

}

for ($i in 1 .. 12) {

}

for ($i in 10 .. 0) {

}

for ($i in @five2[2 .. 6]) {

}

$s1 = 1;
alias End = 4;

for ($i in @five2[$s1 .. End]) {

}

