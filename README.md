# C94 Copybook

## インストール

- Docker
- docker-compose

### 校正

```
$ make lint
```

### PDF生成

```
$ make
```

### その他

筆者の個人利用目的で作られた環境であるため、用途によってはtextlintの設定などを変えるとより良い校正環境が得られます。その際は[textlint-rule-preset-japanese](https://github.com/azu/textlint-rule-preset-japanese)などを参考にしてください。

このリポジトリの初回セットアップ時、実行環境によって、Docker環境下では `npm install` できない現象が起きています。また、そのような環境では `npm install` 後の `postinstall` が実行されない場合があります。これらの現象が発生する場合、Docker環境外で `npm install` を実行し、 `docker run -it -v /media/:media/mount/ vvakame/review /bin/bash` などを使ってDocker環境にマウントして利用してください。

### カスタマイズ箇所

- 印刷向けにPDFリンク色を変更する `\hypersetup{linkcolor=black}` を挿入
- 数式・図表利用向けに `\usepackage{amsmath,amssymb,multirow}` を挿入
- A5印刷向け (それ以外の紙面サイズ利用時は [Re:VIEW Template](https://github.com/TechBooster/ReVIEW-Template) を参考にしてください）
