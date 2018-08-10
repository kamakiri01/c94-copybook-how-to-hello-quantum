「量子コンピュータや量子プログラミングに興味はあるが、何から手を付けたら良いか分からない」という方は多いのではないでしょうか。
量子を使うと何が変わるのか、0と1を同時に表現すると何が便利ですごいのか。これらは量子情報の研究者や量子コンピュータを研究開発する企業、報道関係者など、量子コンピュータに関わる人が常に苦心しながら様々な表現を試みています。

量子コンピュータの開発企業でもあるIBMでは、少しでも量子コンピュータについて理解してもらうための試みとして、スマートフォン向けゲームを提供しています。このコピー本では、このゲームの遊び方、特に、独特な量子状態の表現方法について紹介します。

==  Hello Quantum
Hello Quantumと名付けられたこのゲームは、2つの量子ビットを操作して目的の状態を目指すパズルです。X・Z・H・CZといった基本的な量子ゲートが提供されており、プレイヤーはこれらを順次作用させてパズルを解くことができます。
ゲームはステージ制になっており、最善手の手数が目標として示されています。レベルが上がるほど利用できる量子ゲートの種類や必要な手数が増えるようになっています。

//image[image0][プレイ画面。Google Playアプリページより（iOS版もあります）][scale=0.2]

== 画面の見方

画面下の2つがそれぞれ量子ビットの状態を示します。以下の図では右下が第一量子ビット、左下が第二量子ビットです。

//image[image1][基本の量子状態][scale=0.8]

== 量子ビット

1つの量子ビットは2つのグリッドで構成され、グリッドそれぞれには、黒丸・白丸・輪郭だけの丸のいずれかが入っています。

2つのグリッドはその量子ビットに対してどのような基底で測定するか、グリッド内の丸は測定結果としてどのような結果が得られるかを表しています。

黒丸はその基底における基底状態を、白丸は励起状態が得られることを示します。輪郭だけの丸は、その基底での測定結果はランダムに得られることを示しています。
基底における基底状態、という言い回しはわかりづらいのですが、測定に用いる基底は直交する状態ベクトルのペアであり、|0>と|1>のペア（計算基底と呼ばれるもの）や|+>と|->のペアです。
基底状態とは、普通のコンピュータのビットで言えば電圧が低い状態、励起状態とは電圧が高い状態に相当します。

//image[image2s][単一量子ビットの例][scale=0.3]

黒丸は計算基底における基底状態|0>を、白丸は励起状態|1>を、輪郭はランダムで不定であることを示します。
同様に、上側の格子にも丸が入っています。こちらは|+>|->基底における状態を表しており、黒丸は|+>|->基底における基底状態（つまり|+>）を、白丸は励起状態|->を得られることを示します。

//image[image2][各量子状態][scale=0.75]

Hello Quantumで操作できる量子ビットは2つあるので、それぞれがとりうる状態の数は組み合わせの数だけあります。これを表現しているのが中央の4つの格子です。
それぞれ量子ビットから、グリッドに沿って中央向けてに伸ばした時、中央の4つのグリッドのどれかで交差します。
ここに2つの量子ビットの状態に応じて丸を書き込みます。
つまり、グリッドのどこに丸が書きこまれているか見れば、2つの量子ビットを測定したとき、どのような測定結果が得られるか知ることができます。

//image[image4][中央のグリッドの例][scale=0.5]

どのグリッドに黒丸が書きこまれるかは、以下の法則にまとめられます。

//table[statelist][量子ビットと中央グリッドの黒丸の対応]{
グリッド位置	条件	状態ベクトル
----------------------------
トップ	Z・Z基底測定で2量子ビットの測定物理量は一致	|++> or |-->
ボトム	X・X基底測定で2量子ビットの測定物理量は一致	|00> or |11>
レフト	X・Z基底測定で2量子ビットの測定物理量は一致	|0+> or |1->
ライト	Z・X基底測定で2量子ビットの測定物理量は一致	|+0> or |-1>
//}

白丸が書き込まれた場合、一致ではなく不一致することを示します。例えばグリッドのトップに白丸があれば、それは|+-> or |+->状態を表します。

//table[statelist][量子ビットと中央グリッドの白丸の対応]{
グリッド位置	条件	状態ベクトル
----------------------------
トップ	Z・Z基底測定で2量子ビットの測定物理量は不一致	|+-> or |-+>
ボトム	X・X基底測定で2量子ビットの測定物理量は不一致	|10> or |01>
レフト	X・Z基底測定で2量子ビットの測定物理量は不一致	|0-> or |1+>
ライト	Z・X基底測定で2量子ビットの測定物理量は不一致	|+1> or |-0>
//}

== 基本的な量子ゲート

Hello QuantumではX・Z・Hの量子ゲートを作用させることができます。これは実際にアプリでゲートを作用させて眺めたほうが分かりやすいのではないでしょうか。

注意点として、Hello Quantumでは負の係数は表現されていません。つまり、|1> にZを作用させると-|1>になりますが、この-は可視化されないということです。

//image[image5][係数は表現されない][scale=0.75]

これはHello Quantum作者の一人James Woottonも言及しており、@<fn>{3state}この表現には1量子ビットあたりグリッドが3つ必要になり、
2量子ビットを正確に表すためには中央のグリッドが9つ、合計で15のグリッドが必要になってしまうとされています。
//footnote[3state][https://medium.com/qiskit/hello-quantum-2c1c00fe830c]


== CZを用いたセパラブルでない量子状態
Hello QuantumのLevel.3からは、CZゲート（制御Zゲート）を利用できるようになります。これは2量子ビットに作用するので、他の量子ゲートと組み合わせることで重ね合わせ状態を作れるようになります。
これもアプリ上で作用させるのが直観的で分かりやすいですが、CZを作用させると、各量子ビットと中央のグリッドの接線を軸に丸の位置を交換します。

例として、|-->に対してCZを作用させることを考えます。

//image[image6][|-->][scale=0.5]

これにCZを作用させると、

//image[image7][|--> - |11>][scale=0.5]


|--> - |11>になります。|--> - |11>は重ね合わせ状態なので、各量子ビットの状態は一意に定まっていません。よって、左右下のグリッドはすべて輪郭だけの丸になります。

また、|--> - |11>を状態ベクトルをもとに変形すれば、|0-> - |1+>や|-0> - |+1>に置き換えることができます。

//texequation{
    \begin{split}
		\left| -- \right> - \left| 11 \right> =& \frac{1}{2} \left( \left| 00 \right> - \left| 01 \right> - \left| 10 \right> + \left| 11 \right> \right) + \left| 11 \right> \\
		&= \frac{1}{2} \left( \left| 00 \right> - \left| 01 \right> - \left| 10 \right> - \left| 11 \right> \right) \\
		&= \left| 0- \right> - \left| 1+ \right> = \left| -0 \right> - \left| +1 \right>
    \end{split}
//}

|0-> - |1+>ということは、先の表で言えばグリッドのレフトに白丸があるということです。同様に、|-0> - |+1>はライトに白丸があります。
グリッドのレフトとライトに白丸があることは、@<img>{image7}のグリッドの状態と同じです。




== 補足

Hello Quantumについて良く分かっていない挙動として、|10>-|01>に対してCZを作用させると、本来作用しないはずのパウリZが作用し、グリッドトップの丸が黒に反転します。
これはバグなのか、著者の理解が足りていないためなのかは調査中です。
