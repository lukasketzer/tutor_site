<script>
    import Guide from "$lib/ssh/ssh.md";
    import { guideMarkdown } from "$lib/ssh/guide.js";

    /** @type {"idle" | "copied" | "error"} */
    let copyState = "idle";
    /** @type {ReturnType<typeof setTimeout>} */
    let resetTimer;

    async function copyGuide() {
        try {
            await navigator.clipboard.writeText(guideMarkdown);
            copyState = "copied";
        } catch {
            copyState = "error";
        }
        clearTimeout(resetTimer);
        resetTimer = setTimeout(() => (copyState = "idle"), 2000);
    }
</script>
<svelte:head>
    <link
        rel="stylesheet"
        href="https://cdnjs.cloudflare.com/ajax/libs/github-markdown-css/5.5.1/github-markdown-dark.min.css"
        integrity="sha512-MmL2FuLmm/UH05Ah4JiJwA+G7OCceZDpzGHWqsju4Espzq+9nwQJdQVMNZPd1FNK2H3qDYXdET7HNG7Qm93FEg=="
        crossorigin="anonymous"
        referrerpolicy="no-referrer"
    />
</svelte:head>

<div>
    <div class="guide-header">
        <h1 class="title is-2" id="ssh-guide">
            <a href="#ssh-guide" class="anchor" aria-hidden="true" tabindex="-1">#</a>SSH Guide
        </h1>
        <button
            class="copy-button"
            on:click={copyGuide}
            title="Kompletten Guide als Markdown kopieren"
            aria-live="polite"
        >
            <i class={copyState === "copied" ? "bi bi-check2" : copyState === "error" ? "bi bi-x-lg" : "bi bi-copy"} aria-hidden="true"></i>
            <span>{copyState === "copied" ? "Kopiert!" : copyState === "error" ? "Fehlgeschlagen" : "Seite kopieren"}</span>
        </button>
    </div>
    <div class="container markdown-body">
        <Guide />
    </div>
</div>
<style>
    /* same width and side padding as .markdown-body, so the title lines up with the text */
    .guide-header {
        display: flex;
        align-items: center;
        flex-wrap: wrap;
        justify-content: space-between;
        gap: 0.75rem;
        box-sizing: border-box;
        max-width: 980px;
        margin: 0 auto 1.5rem;
        padding: 0 45px;
    }
    .anchor {
        margin-right: 0.3em;
    }
    .guide-header .title {
        margin-bottom: 0;
    }
    .copy-button {
        display: inline-flex;
        align-items: center;
        justify-content: center;
        gap: 0.5rem;
        flex-shrink: 0;
        min-width: 9rem;
        padding: 0.4rem 0.9rem;
        border: 1px solid #8b949e;
        border-radius: 2px;
        background: none;
        color: #c9d1d9;
        font-size: 1rem;
        line-height: 1.4;
        cursor: pointer;
        transition: border-color 0.15s, color 0.15s;
    }
    .copy-button:hover,
    .copy-button:focus-visible {
        border-color: #e6edf3;
        color: #e6edf3;
    }
    .markdown-body {
        box-sizing: border-box;
        min-width: 200px;
        max-width: 980px;
        margin: 0 auto;
        padding: 45px;
        background-color: #14161a;
    }

    @media (max-width: 767px) {
        .markdown-body {
            padding: 15px;
        }
        .guide-header {
            padding: 0 15px;
        }
    }
    /* the guide is rendered by a child component, so the rule must be global */
    .markdown-body :global(code) {
        white-space: pre-line;
    }
</style>
