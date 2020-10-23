const UNICODE_START = "a".charCodeAt(0);

class trieNode {
  constructor() {
    this.children = Array(26).fill(null);
    this.end = false;
    this.empty = true;
  }

  // assume v is char
  update(v) {
    const i = v.charCodeAt(0) - UNICODE_START;
    if (this.children[i] === null) {
      this.children[i] = new trieNode();
      this.empty = false;
    }
    return this.children[i];
  }

  get(v) {
    const i = v.charCodeAt(0) - UNICODE_START;
    return this.children[i];
  }

  setEnd() {
    this.end = true;
  }
}

var findWords = function (board, words) {
  const map = new Map();
  const trieRoot = new trieNode();
  words.forEach((word) => {
    let cur = trieRoot;
    for (const c of word) {
      cur = cur.update(c);
    }
    cur.setEnd();
  });
  const foundWordSet = new Set();

  for (let row = 0; row < board.length; row++) {
    for (let col = 0; col < board[row].length; col++) {
      innerFind(board, trieRoot, "", row, col, foundWordSet);
    }
  }

  return Array.from(foundWordSet);
};

function innerFind(board, trieRoot, path, r, c, foundWordSet) {
  if (r >= board.length || r < 0 || c >= board[0].length || c < 0) {
    return;
  }
  if (board[r][c] === null) return;
  if (trieRoot.get(board[r][c]) === null) return;

  const charHolder = board[r][c];
  const newRoot = trieRoot.get(charHolder);
  path += charHolder;
  if (newRoot.end) {
    foundWordSet.add(path);
    if (newRoot.empty) {
      return;
    }
  }
  board[r][c] = null;

  innerFind(board, newRoot, path, r + 1, c, foundWordSet);
  innerFind(board, newRoot, path, r - 1, c, foundWordSet);
  innerFind(board, newRoot, path, r, c + 1, foundWordSet);
  innerFind(board, newRoot, path, r, c - 1, foundWordSet);

  board[r][c] = charHolder;
}
