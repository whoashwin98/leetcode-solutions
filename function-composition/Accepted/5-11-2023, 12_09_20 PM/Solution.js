// https://leetcode.com/problems/function-composition

/**
 * @param {Function[]} functions
 * @return {Function}
 */
var compose = function(functions) {
	return function(x) {
        console.log(x)
        for(var i=functions.length - 1; i >= 0; i--) {
            var f = functions[i]
            x = f(x)
            console.log(x, f)
        }
        return x
    }
};

/**
 * const fn = compose([x => x + 1, x => 2 * x])
 * fn(4) // 9
 */