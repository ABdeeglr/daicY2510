# README


## Git Commit Rules:

**核心提交类型**

1. feat - 新功能 | feat: 添加用户登录功能 | feat(auth): 实现OAuth2.0认证
2. fix - 错误修复 | fix: 修复登录页面闪退问题 | fix(api): 修正用户数据查询接口
3. docs - 文档更新 | docs: 更新API使用说明 | docs(readme): 添加安装指南
4. style - 代码样式调整 | style: 调整代码缩进格式 | style(component): 统一按钮样式命名
5. refactor - 代码重构 | refactor: 重构用户模块代码结构 | refactor(database): 优化数据库查询逻辑
6. perf - 性能优化 | perf: 优化图片加载性能 | perf(render): 减少页面重绘次数
7. test - 测试相关 | test: 添加用户服务单元测试 | test(e2e): 完善端到端测试用例
8. chore - 构建/工具变更 | chore: 更新webpack配置 | chore(deps): 升级React到18版本

### Sample

feat(user): 添加用户头像上传功能

- 支持JPG/PNG格式
- 添加图片压缩处理
- 增加文件大小验证

