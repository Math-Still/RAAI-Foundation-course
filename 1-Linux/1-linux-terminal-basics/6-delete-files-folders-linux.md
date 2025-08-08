# 终端基础：在 Linux 中删除文件和文件夹

>via: [https://linux.net.cn/article-15809-1.html](https://linux.net.cn/article-15809-1.html)
>
>source: [https://itsfoss.com/delete-files-folders-linux/](https://itsfoss.com/delete-files-folders-linux/)
>
>作者：[Abhishek Prakash](https://itsfoss.com/author/abhishek/)
>
>选题：[lkxed](https://github.com/lkxed/)
>
>译者：[geekpi](https://github.com/geekpi)
>
>校对：[wxy](https://github.com/wxy)
>
>本文由 [LCTT](https://github.com/LCTT/TranslateProject) 原创编译，[Linux中国](https://linux.net.cn/) 荣誉推出

> 你已经学会了创建文件和目录。现在是时候学习如何在命令行中删除文件和文件夹了。

在终端基础系列的前几章中，你学习了 [创建新文件][1] 和 [目录][1a]（文件夹）。

现在让我们看看如何在 Linux 终端中删除文件和文件夹。

## 删除文件

要删除文件，你可以按以下方式使用 `rm` 命令：

```Bash
rm filename_or_path
```

如果文件已成功删除，你将看不到任何输出。

这是一个示例，其中我删除了一个名为 `new_file` 的文件。当我列出目录内容时，你可以看到 `new_file` 不再存在。

![](images/chapter6-remove-multiple-files-linux-terminal_a2837ab6.webp)

*删除单个文件*

你还可以在同一命令中删除多个文件：

```Bash
rm file1 file2 file3
```

让我展示一个在单条命令中删除两个文件的示例。

![](images/chapter6-delete-files-linux-terminal_150ac34a.webp)

*删除多个文件*

### 🏋️练习文件删除

让我们练习一下刚刚学到的东西。创建一个名为 `practice_delete` 的目录并切换到该目录：

```Bash
mkdir practice_delete && cd practice_delete
```

现在创建一些空文件：

```Bash
touch file1 file2 file3
```

删除 `file3`:

```Bash
rm file3
```

现在，让我们做一些额外的事情。运行此命令并更改 `file2` 的权限：

```Bash
chmod u-w file1 file2
```

现在尝试删除 `file2`：

```Bash
rm file2
```

你是否看到消息 “**remove write protected file**”？ 那是因为你从这个文件中删除了写权限（用于修改）。

你可以**按 `Y` 或回车键确认删除或按 `N` 拒绝删除。**

如果你不想看到这条消息并仍然删除它，你可以使用强制删除选项 `-f`。通过删除 `file1` 试试：

```Bash
rm -f file1
```

以下是上述所有示例的重放：

![](images/chapter6-file-delete-example_34e6fbc6.svg)

!!! warning "🚧"

    Linux 命令行中没有垃圾桶。一旦文件被删除，你就无法像在图形文件管理器中那样撤消将其从垃圾箱中取回的操作。因此，删除文件时要格外小心。

### 小心删除

缺少垃圾桶使删除成为一种永久性的工作。这就是为什么你应该注意要删除的文件的原因。

有一个带 `-i` 选项的交互模式。有了这个，你会被要求确认删除。

```Bash
rm -i filename
```

当你根据特定模式删除多个文件时，这很有用。

这是一个示例，其中我以交互方式删除名称中匹配 `file_` 模式的所有文件。我删除了一些并在交互模式下保留了一些。

![](images/chapter6-interactive-delete-example_7a020aba.svg)

!!! question "💡"

    我建议切换到文件所在的目录，然后删除它们。这有助于减少由文件路径中的拼写错误引起的任何可能性。

## 删除目录

在 Linux 中有专门的 `rmdir` 命令来删除目录。

```Bash
rmdir dir_name
```

但是，它只能删除空目录。如果目录中有任何文件或子目录，`rmdir` 命令将抛出错误。

```Bash
$ rmdir dir2
rmdir: failed to remove 'dir2': Directory not empty
```

这使得它在大多数情况下用处不大。

那么，如何删除非空文件夹呢？ 好吧，使用与之前删除文件相同的 `rm` 命令。

是的，相同的 `rm` 命令，但带有递归选项 `-r`：

```Bash
rm -r dir_name
```

### 🏋️练习文件夹删除

让我们练习你学到的东西。

如果你还没有，请切换到 `practice_delete` 文件夹。现在，创建两个目录 `dir1` 和 `dir2`。

```Bash
mkdir dir1 dir2
```

在 `dir2` 中创建一个文件：

```Bash
touch dir2/file
```

现在尝试使用 `rmdir` 命令删除目录：

```Bash
rmdir dir1
```

```Bash
rmdir dir2
```

由于 `dir2` 不为空，`rmdir` 命令将失败。相反，使用带有递归选项的 `rm` 命令：

```Bash
rm -r dir2
```

以下是上述所有命令示例的重放：

![](images/chapter6-folder-delete-example_2f7103af.svg)

!!! question "💡"

    交互式删除模式在使用 `rm` 命令的递归选项删除目录时更有帮助：

```Bash
rm-ri dir_name
```

因此，你学会了使用 Linux 命令删除文件和文件夹。是时候多练习了。

## 📝 测试你的知识

准备一个如下所示的目录树：

```Text
.
├── dir1
│   ├── file1
│   ├── file2
│   └── file3
├── dir2
├── dir3
└── file
```

基本上，你在当前目录（`practice_delete`）中创建一个名为 `file` 的文件和三个目录 `dir1`、`dir2` 和 `dir3`。然后在 `dir1` 中创建文件 `file1`、`file2` 和 `file3`。

现在执行以下操作：

- 删除 `file2`。
- 切换到 `dir3` 并强制删除上层目录中名为 `file` 的文件。
- 删除 dir1 的所有内容，但不删除目录本身。
- 列出 `dir` 的内容。

一切进展顺利。你已经学习了一些基本知识，例如切换目录、检查目录内容、创建和删除文件和目录。在下一章中，你将学习如何在终端中复制文件和文件夹。敬请关注！