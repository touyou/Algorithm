# Algorithm
アルゴリズムの概要をまとめる。いつかできる言語で実装していきたい。  
READMEに関するプルリクは適宜お待ちしています。画像など追加してもらっても構いません。ただコードに関しては後ほど実装していく予定なので書いていただいてもマージしないと思います。

# データ構造
## リスト・スタック・キュー

- スタック ... 後入れ先出しのデータ構造
- キュー ... 先入れ先出しのデータ構造

## 木

### 優先度つき待ち行列（ヒープ）

必ず根が最小になるような二分木。子は必ず親より大きくなければならない。末尾に挿入し、逆転がなくなるまで遡っていく。削除の場合は末尾を根に持ってきて、逆転がなくなるまでたどる。

### 2分探索木

左の子より親が大きく、親より右が大きいような二分木。親から挿入するべきところに辿っていき挿入する。

### 2-3木

中間ノードは二つの基準値を持っている。左の値より小さい要素は左の部分木に、二つの中間の値は真ん中の部分木に、右の値より大きい要素は右の部分木に含まれる。各ノードは最大３つまでしか子供をもてない。葉ノードに要素が挿入される。

### AVL木

基本的には２分探索木だが、左右の部分木の高さの差が1未満になっている平衡二分木のこと。

## ハッシュ

ハッシュ関数というものがあって、各データにハッシュ値が割り当てられそれによって管理される。  

### チェイン法

チェイン法とはハッシュ値が衝突した時に、そのままハッシュ表にデータを追加する方法。そのままだと衝突する値が多い場合オーダーが悪くなるのでハッシュ表の各項目を別のデータ構造で管理することも。

### 開番地法、オープンアドレス法

衝突した時に、衝突しないあらたなハッシュ値を追加するという再ハッシュという手法を使う方法。

## 集合群

Union-Find木のこと。同じ種類ならば同じ根の木に、そうでなければ違う根の木に挿入することで要素の種類を分類する。根同士をつなぐことで複数の集合族を同一の集合族にすることも。

# ソートアルゴリズム
## バブルソート、内挿ソート、選択ソート

- バブルソート ... 隣り合う二つの大小を比較し入れ替えることを繰り返す、O(n^2)
- 挿入ソート ... 一つずつ大小の逆転がおこらないように前からなめながら正しい位置に値を入れていく、O(n^2)
- 選択ソート ... 最大値または最小値を探して配列の端と入れ替えることを繰り返す、O(n^2)

## クイックソート

ピボットを基準に左右の要素を入れ替え、確定してないところに再帰的にそれを適用していく。

## マージソート

配列を二分割し、そのそれぞれにマージソートを適用することを繰り返す。

## ヒープソート

すべてをヒープに挿入して、順に取り出してくる。

## ビンソート, 基数ソート

- ビンソート、バケットソート ... 値の取りうる種類のバケツを用意しておき、そこに振り分けることでソートする
- 基数ソート ... 値を何種類かのキーにで分類し下位のキーの要素からソートしていく

# グラフアルゴリズム
## ダイクストラのアルゴリズム

始点から最も近い点から順番に最短距離を確定させていくことで最短距離を求める。プライオリティキューを使うと高速化できる。

## フロイドのアルゴリズム

全点対最短路を求めるアルゴリズム。DPで求める。d[i][j]=min(d[i][j], d[i][k]+d[k][j])が漸化式。

## DAGの一列化

*すっと出てこないから後回し*

## 有向グラフの強成分の求め方

適当な頂点からまずDFSしながら戻る直前に番号をつけていく。その後グラフの辺をすべて逆転し、番号が一番大きいところから通ることのできる頂点の集合に分けていく。

## プリムのアルゴリズム

順にすでに確定している木とその他の頂点を結ぶ最小のコストの辺を付け加えていくことで最小全域木をつくる。

## クラスカルのアルゴリズム

辺をコストの小さい順に見ていき閉路ができなければ追加することで最小全域木をつくる。

## 無向グラフの関節点の求め方

*すっと出てこないから後回し*

# 文字列アルゴリズム
## 文字列の照合 KMPアルゴリズム
### 前処理
パターンに含まれる各文字について、その文字で不一致になったときにパターンをどれだけずらせばよいかをしらべて表にする。  
特に調べたい文字列パターンがtartarのように途中で先頭の数文字が繰り返される場合、すでに一致している部分をあらためて調べなく済むように計算する。最悪O(m^2)になる？

### 本計算
前処理でつくった表を使いずらしながら先頭から調べていく。O(n)

## 文字列の照合 BMアルゴリズム

パターンを後ろから辿っていって、不一致になったら不一致になった文字に応じてずらす量を決める。もしパターンに含まれていない文字で不一致になれば最大m文字ずらせるのでオーダーがO(n/m)になる

## トライ木

一文字ずつ文字列を下に辿りながらノードに格納するとできるような木。wを文字列長、Rをアルファベットの数、Nを要素の数とすれば計算量が最悪O(log_R N)平均O(w)、メモリ量がRNからRNwになる。

# 手法
## 分割統治法

ある問題を小さい問題に分割して解く手法

## 動的計画法

直前までの結果を利用して次の結果を計算していくような計算手法。帰納法っぽいやつ。

## 欲張り法

一番いいところから順に扱っていくことで解く手法。
