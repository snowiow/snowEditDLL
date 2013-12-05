        $else = -1; /// done
        $if = -2; /// done
        @const = null; /// done
        */

        $i = 0;
        $i++;

        //$j++; /// fails - done

        $var = null; /// done
        //$var = 12; /// fails - done

        $foo = 1 + 2 * 3; /// done
        $bar = true; /// done
        //$quatz = true + false; /// fails - done
        $one = 123.4; /// done
        $two = 42; /// done
        $three = 42 - 8; /// done
        $four = 1 + 2 * 3 - 4; /// done

        const $pi = 3.14; /// done

        const $test = $four; /// done
        $three = $test + 2; /// done

        //$test = 12; /// fails - done
        $cond = true; /// done
        $cond = false; /// done
        $cond = !$bar;

        //const $three = 3; /// fails - done
        //$three = int; /// fails - done

        //$var_plus = +; /// fails - done
        //$var_plus2 = $one +; /// fails - done
        //$var_plus3 = + $one; /// fails - done
        $var_plus4 = $one + $test; /// done

        $foo = $one + $two + cast<int>($pi); /// done

        $ptr1 -> $two; /// done
        $ptr2 <- $ptr1; /// done
        //$ptr3 -> $ptr1; /// fails - done
        //$ptr_c = &$one; /// fails - done

        $var -> $foo;

        const $ptr_const -> $test; /// done
        const $const_ptr_deref <- $ptr_const; /// done

        $ptr4 = null; /// done
        //$ptr1 = null; /// done

        //$ptr_x1 -> null; /// fails - done
        $ptr_x2 = $ptr4; /// done
        //$ptr_x22 = $ptr4 + 3; /// fails - done
        //$ptr_x3 <- $ptr4; /// fails - done
        //$ptr_x4 <- null; /// fails - done
        //$ptr_exp = null + 4; /// fails - done
        //$ptr_exp1 -> $pi + 4; /// fails - done
        //$ptr_exp2 <- $ptr1 + 4; /// fails - done
		
        $ptr_exp_t2 = $ptr1 + 2; /// done

        @five = [1, 2, 3, 4]; /// done
        const @five2 = [$one, $two, 3, $four, 5, 6]; /// done
        const @five3 = [$one + 31, $two, 3, $four - 7, 5, 6]; /// done

        @five_unint = null; /// done
        @five_unint = [1, 2, 3]; /// done
        @five_int = [255, 0, 255]; /// done
        @five_int = null; /// done

        @five7 = @five; /// done
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

        @five = @five2; /// done - fails
        @five4 = [@five[0], @five[1] + 2, 13.37]; /// done - fails
        @five4 = [@five[0], @five[1] + 2, 13, 37]; /// done

        alias PI = 3.14; /// done
        //alias PI = 3.14; /// fails - done

        alias AnswerOfLife = $two; /// done
        alias Fail = PI + $two; // done

        alias PIx2 = PI * 2; /// done
        alias Pi = PI; /// done

        $pi_2 = PI; /// done
        $pi_2x2 = PIx2; /// done

        @five[] = 42;

        if (true) {
                $my_if_foo = 1;
        }

        if (false) {
                $my_if_bar = 2;
        }

        if ($pi == PI) {

        }

        if (true && false) {
                $my_if_foo = 1;
        }

        if ($pi == 2 || $pi < 4) {
                $my_if_bar = 2;
        }

        if ($pi != 2) {

        }

        if (!true) {

        }

        if (!false) {

        }

        if (!$cond) {

        }

        if (!$pi) {

        }

        $cond2 = 5 > 4;
        $cond3 = !$cond2;
        $cond31 = !$cond3;
        $cond32 = $cond3 && $cond2;
        $cond321 = !($cond3 && $cond2); /// TODO
        $cond33 = !$cond3 && $cond2;

        $cond4 = 5 < 2 && 4 > 2;
        $cond5 = $cond2 && $cond3 || $cond4;
        $cond6 = $cond5 && $cond4 || $cond3 && $cond2;
        $cond7 = !$cond33 && !$cond6;
