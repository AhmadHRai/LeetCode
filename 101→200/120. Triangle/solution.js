/**
 * @param {number[][]} triangle
 * @return {number}
 */
var minimumTotal = function(triangle) {
    for (let i = triangle.length-2; i >= 0; i--)
        for (let j = 0; j < triangle[i].length; j++)
            triangle[i][j] += Math.min(triangle[i+1][j], triangle[i+1][j+1])
    return triangle[0][0]
}

/**
or using ~
var minimumTotal = function(T) {
    for (let i = T.length - 2; ~i; i--) 
        for (let j = T[i].length - 1; ~j; j--) 
            T[i][j] += Math.min(T[i+1][j], T[i+1][j+1])
    return T[0][0]
}
 */