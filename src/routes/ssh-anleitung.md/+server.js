import guide from "$lib/ssh/ssh.md?raw";

export const prerender = true;

// Markdown version of the SSH guide, linked from /llms.txt. Not named ssh.md:
// Apache MultiViews on the host would then treat it as a variant of /ssh.
// The relative screenshot link would be broken here, so it is dropped.
const body = "# SSH-Anleitung für die Rechnerhalle der TUM\n\n" +
    guide.replace(/^!\[.*\]\(\.\/powershell\.png\)\n?/m, "");

export function GET() {
    return new Response(body, {
        headers: { "content-type": "text/markdown; charset=utf-8" },
    });
}
