'use strict'

process.stdin.resume()
process.stdin.setEncoding('utf-8')

let inputString = ''
let currentLine = 0

process.stdin.on('data', inputStdin => {
  inputString += inputStdin
})

process.stdin.on('end', _ => {
  inputString = inputString
    .trim()
    .split('\n')
    .map(string => {
      return string.trim()
    })

  main()
})

function readline() {
  return inputString[currentLine++]
}
// Make a Snippet for the code above this and then write your logic in main();

function main() {
  var a = readline().split(' ')
  console.log(Math.ceil(a[0] / a[2]) * Math.ceil(a[1] / a[2]))
}
